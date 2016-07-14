module JKFlipFlop(J, K, clk, Q);
input J, K, clk;
output Q;
reg Q;
reg Qm;
always @(posedge clk)
if(J == 1 && K == 0)
Qm <= 1;
else if(J == 0 && K == 1)
Qm <= 0;
else if(J == 1 && K == 1)
Qm <= ~Qm;// always @(negedge clk)
Q <= Qm;
endmodule
