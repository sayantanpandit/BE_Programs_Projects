
module testALU;

reg [1:0] x;
reg [1:0] y;
reg S0;
reg S1;
wire [1:0] o1;
wire o2;

ALU A ( x, y, S0,S1, o1, o2);

initial
	begin

	x = 2'b01;
	y = 2'b01;
	S1 = 1'b0;
	S0 = 1'b0;
	$monitor ("Adder %b %b %b %b %b %b", x, y, S0,S1, o1, o2);

	#5 x = 2'b10;
	y = 2'b01;
	S1 = 1'b0;
	S0 = 1'b1;
	$monitor ("Subtractor %b %b %b %b %b %b", x, y, S0,S1, o1, o2);

	#5 x = 2'b01;
	y = 2'b10;
	S1 = 1'b1;
	S0 = 1'b0;
	$monitor ("Nor %b %b %b %b %b %b", x, y, S0,S1, o1, o2);


	#5 x = 2'b10;
	y = 2'b11;
	S1 = 1'b1;
	S0 = 1'b1;
	$monitor ("Nand %b %b %b %b %b %b", x, y, S0,S1, o1, o2);

	#5 $finish;
	end

endmodule
