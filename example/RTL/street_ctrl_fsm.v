//---------------------------------------
//
//  FSM of traffic light 
//  two street use same FSM module
//  will be instanciated into traffic.v
//
//--------------------------------------
module street_ctrl_fsm(clk, rst, waiting, waiting_cross, light_cross, red,yellow, green, light_out);

input  		rst;
input  		clk;
input  		waiting;
input  		waiting_cross;
input  [4:0]    light_cross;
output 		red;
output 		yellow;
output 		green;
output [4:0]    light_out;

parameter 	PRIORITY = 0;
parameter 	MAX_WAIT = 4;

parameter [4:0] RESET = 5'b00001,
	        S_RED0 = 5'b00010,
		S_RED1 = 5'b00100,
		S_YELLOW  = 5'b01000,
		S_GREEN  = 5'b10000;

//register to remember the status of traffic light.
reg [4:0] light_out, next_state;
reg red, yellow, green;

//register to count time that green light hold.
reg[3:0]  count;

//state register update.
always @(posedge clk) begin
	if (rst)
		light_out <= RESET;
	else 
		light_out <= next_state;


end
//Timer for cross street waiting time
//so once jump to green light, minmum holding time is 4 clock cycle.
//if green light is too short, this is dangerous.
//if the other road is not busy, then we can hold green even longer than 4.


always @(posedge clk) begin
	if(rst)
		count <= 4'b0001;
	else begin
		if(light_out == S_RED1 && next_state == S_GREEN)
			count <= 4'b0001;
		else if (count != MAX_WAIT)
			count <= count + 4'b0001;
	end
end

//Next state logic
//the main logic for state jumping (traffic light FSM)
always @(*)
begin
	case(light_out)
		RESET : begin
                        if(PRIORITY) next_state = S_GREEN;
			else next_state = S_RED0;
		end
		S_RED0   : begin
			next_state = S_RED1;
		end
		S_RED1   : begin
                        if(light_cross == S_YELLOW) next_state = S_GREEN;
			else next_state = S_RED1;
		end
	        //if current is green and other road is busy, and current road
		//is not busy, or green is already hold long(MAX_WAIT),then it
		//is ready to jump to green.
		S_GREEN    : begin
			if(waiting_cross &&(~waiting || count == MAX_WAIT))
			next_state = S_YELLOW;
		        else next_state = S_GREEN;
		end
		S_YELLOW    : begin
			next_state = S_RED0;
	       	end
		default : next_state = 5'bxxxxx;
	endcase

end

always @(light_out)

begin
	case(light_out)
`ifdef RTL_BUG
	RESET:
		begin
			red = 0;
		        green = 1;
		        yellow = 0;	
		end

	S_RED0,S_RED1:
		begin
			red = 1;
		        green = 0;
		        yellow = 0;	
		end
`else
	RESET, S_RED0,S_RED1:
		begin
			red <= 1;
		        green <= 0;
		        yellow <= 0;	
		end
`endif
	S_GREEN:
		begin
			green <= 1;
			red <= 0;
			yellow <= 0;
		end
	S_YELLOW:
		begin
			yellow <= 1;
			green <= 0;
			red <= 0;
		end
	default :    
		begin
			red <= 0;
		 	green <= 0;
			yellow <= 0;
		end	

	endcase
end
		
//customer can create assertion or assume here.
//seperate assertions here
always @(posedge clk or posedge rst) begin 
	//rst is high valid
	//during rst, do not check behaviors
	if(rst) begin
	end
	else begin
		`ifdef FORMAL
			timer_check_1: assert property (count <= MAX_WAIT);
			timer_check_2: assert (count >= 1);
			traffic_light_test: assert (red | yellow | green);
		`endif
	end

end


endmodule
