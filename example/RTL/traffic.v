//-----------------------
//  Traffic design top
//
//  customer need to set traffic situation for two street
//  waiting_main: main street is busy, there are traffic
//  waiting_first: first street is busy, there are traffic
//  
//-----------------------

module traffic(green_main, yellow_main, red_main, green_first, yellow_first,
	red_first,clk,rst,waiting_main, waiting_first);
	
input  rst;
input  clk;
input  waiting_main;
input  waiting_first;
output green_main, yellow_main, red_main, green_first, yellow_first, red_first;


//parameter MAX_WAIT=4;

//the traffic light state for two cross street
wire [4:0] state_first ;
wire [4:0] state_main ;

//FSM of traffic light for street_main 
street_ctrl_fsm #(1,5) main(.clk (clk),
	.rst       	(rst),
	.waiting   	(waiting_main),
	.waiting_cross 	(wating_first),
	.light_cross 	(state_first),
	.red		(red_main),
	.yellow 	(yellow_main),
	.green 		(green_main),
	.light_out	(state_main)

	);
//FSM of traffic light for street_first
street_ctrl_fsm #(0,5) first(.clk (clk),
	.rst       	(rst),
	.waiting   	(waiting_first),
	.waiting_cross 	(wating_main),
	.light_cross 	(state_main),
	.red		(red_first),
	.yellow 	(yellow_first),
	.green 		(green_first),
	.light_out	(state_first)

	);


//seperate assertions here
always @(posedge clk or posedge rst) begin 
	//rst is high valid
	//during rst, do not check behaviors
    if(!rst) begin
	`ifdef FORMAL
		no_two_green: assert property (!(green_main & green_first) );
	`endif
end

end
endmodule
