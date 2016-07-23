module test_bench1;

reg [3:0] a;
reg [3:0] b;

wire [3:0] sum;
wire carry;

adder_4bit adder ( a, b, sum, carry);

initial
	begin

	a = 4'b0101;
	b = 4'b1010;
	$monitor ("%b %b %b %b", a, b, sum, carry);

	#5 a = 4'b0000;
	b = 4'b1101;
	$monitor ("%b %b %b %b", a, b, sum, carry);

	#5 a = 4'b1011;
	b = 4'b1111;
	$monitor ("%b %b %b %b", a, b, sum, carry);


	end

endmodule