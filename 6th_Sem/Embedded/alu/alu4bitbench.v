module testbench4bit;
 reg [1:0]a;
 reg [3:0]b;
 reg [3:0]c;

wire [3:0]s;
alutest alutest_bench(a,b,c,s);
initial
   
   begin
            a=2'b00;
            b=4'b0010;
            c=4'b0011;
       $monitor("%b %b %b %b",a,b,c,s);
  end
     
endmodule