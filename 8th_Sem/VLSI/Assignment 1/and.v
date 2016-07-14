module AND1(a,b,c);
input a,b;
output c;
wire c;
assign c = a & b;
endmodule
module OR1(a,b,c);
input a,b;
output c;
wire c;
assign c= a | b;
endmodule
module NOT1(a,b);
input a;
output b;
wire b;
assign b = ~a;
endmodule
