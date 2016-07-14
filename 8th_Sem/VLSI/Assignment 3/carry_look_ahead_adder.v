module u8binary_carry_look_ahead_adder (input [7:0] IN1,IN2, output [7:0] SUM, output CY,AC);

  wire [7:0] P,G,C;
  assign C[0] = 0;
  assign P = IN1^IN2;
  assign G = IN1&IN2;
  
  genvar i;
  for (i=1;i<=7;i=i+1)
    assign C[i] = G[i]|(P[i]&C[i-1]);

  assign SUM = P^C;
  assign CY = C[7];
  assign AC = C[4];

endmodule

module testbench_adder(in1,in2,sum,ac,cy);

input [7:0] in1, in2;
output [7:0] sum;
output cy, ac;

assign in1 = 8'b10101010;
assign in2 = 8'b11010101;
u8binary_carry_look_ahead_adder adder1(in1,in2,sum,cy,ac);
endmodule
