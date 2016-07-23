
module alutest(a,b,c,s);
input [1:0]a;
input [3:0]b;
input [3:0]c;
output [3:0]s;
reg [3:0]s;
//b=4'0001;
//c=4'0010;
always @(*)
   case(a)
       2'b00:begin
               s=b^c;
                end
       2'b01:begin
               s=b|c;
               end
       2'b10:begin
                s=b&c;
             end
       2'b11:begin
               s=~b;
             end

    endcase  
  //$monitor(" %b ",s);       
endmodule  