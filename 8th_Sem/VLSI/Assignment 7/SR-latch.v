module SR_Latch ( s ,r ,enable ,reset ,q ,qb );

output q ;
reg q ;
output qb ;
reg qb ;

input s ;
wire s ;
input r ;
wire r ;
input enable ;
wire enable ;
input reset ;
wire reset ;

always @ (enable or s or r or reset) begin
 if (reset) begin
  q = 0;
  qb = 1;   
 end else if (enable) begin
  if (s!=r) begin
   q = s;
   qb = r;
  end else if (s==1 && r==1) begin
   q = 1'bZ;
   qb = 1'bZ;
  end
 end
end

endmodule
module testbench_SR(s,r,enable,reset,q,qb);
input s,r,enable,reset;
output q,qb;
wire s, r, enable, reset;
wire q, qb;
assign enable = 1'b1;
assign reset = 1'b0;
//assign s= 1'b0;
//assign r= 1'b0;

SR_Latch SR1(s,r,enable,reset,q,qb);


endmodule
