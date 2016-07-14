module mux1( select, d, q );

input[1:0] select;
input[3:0] d;
output     q;

wire q;
wire[1:0] select;
wire[3:0] d;
assign q = d[select];

endmodule

module testbench_mux(select,d,q);
input[1:0] select;
input[3:0] d;
output q;
wire q;
wire[1:0] select;
wire[3:0] d;
assign select = 2'b00;
assign d = 4'b1101;
mux1 mux_instance(select,d,q);

endmodule
