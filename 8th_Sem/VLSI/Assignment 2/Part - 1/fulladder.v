module fulladder4(Sum,Cout,A,B,Cin);

input [3:0] A,B;
input Cin;

output [3:0] Sum;
output Cout;

wire [3:0] Sum;
wire [2:0] carry;
wire Cout;

fulladder1 one(.s(Sum[0]),.co(carry[0]),.in1(A[0]),.in2(B[0]),.ci(Cin));
fulladder1 two(.s(Sum[1]),.co(carry[1]),.in1(A[1]),.in2(B[1]),.ci(carry[0]));
fulladder1 three(.s(Sum[2]),.co(carry[2]),.in1(A[2]),.in2(B[2]),.ci(carry[1]));
fulladder1 four(.s(Sum[3]),.co(Cout),.in1(A[3]),.in2(B[3]),.ci(carry[2]));

endmodule

module fulladder1(s,co,in1,in2,ci);

input in1,in2,ci;
output s,co;

assign s = in1^in2;
assign co = in1&in2|in1&ci|in2&ci;

endmodule
 
 