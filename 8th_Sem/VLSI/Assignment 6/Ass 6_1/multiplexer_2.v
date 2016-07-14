module mux2( select, d, q );

input[2:0] select;
input[7:0] d;
output     q;

wire q;
wire[2:0] select;
wire[7:0] d;
assign q = d[select];

endmodule

module testbench_mux2(select,d,q);
input[2:0] select;
input[7:0] d;
output q;
wire q;
wire[2:0] select;
wire[7:0] d;
assign select = 3'b001;
assign d = 8'b11011011;
mux2 mux_instance(select,d,q);

endmodule
