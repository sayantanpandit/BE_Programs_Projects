module alu(a,b,s,c,carry);
input [1:0] a,b,s;
output [1:0] c,carry;
reg [1:0] c,carry;
always @* begin
case(s)

2'b00: begin
        c = a ^ b;
	carry[0] = a[0] & b[0];
        carry[1] = (a[1] | b[1]) & carry[0];
        
       $monitor("%b %b %b %b",a,b,c,carry[1]);
       end
2'b01: begin
        c <= a ^ b;
        carry[0] <= (~a[0] & b[0]);
        carry[1] <= carry[0] & (~(a[1] ^ b[1])) | (~a[1] & b[1]);
       $monitor("%b %b %b %b",a,b,c,carry[1]);
       end
2'b10: begin
        c <=  ~(a & b);
       $monitor("%b %b %b",a,b,c);
       end
2'b11: begin
        c <= ~(a | b);
       $monitor("%b %b %b",a,b,c);
       end

 endcase
 end
 endmodule
module testbench_alu;

reg [1:0] a,b,s;
wire [1:0] c,carry;
alu alu_b(.a(a),.b(b),.s(s),.c(c),.carry(carry));
initial
	begin

	a = 2'b01;
	b = 2'b10;
        s= 2'b00;
	$monitor ("%b %b %b %b %b", a, b,s,c,carry[1]);

	#5 a = 2'b00;
	b = 2'b11;
        s=2'b10;
	$monitor ("%b %b %b %b %b", a, b,s, c,carry[1]);

	#5 a = 2'b10;
	b = 2'b11;
        s=2'b01;
	$monitor ("%b %b %b %b", a, b,s,c);
       #5 a=2'b00;
         b = 2'b11;
         s=2'b11;
         $monitor ("%b %b %b%b ", a,b, s,c);



	end
endmodule
