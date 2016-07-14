module decoder(din,dout);
output [3:0] dout ;
reg [3:0] dout ;

input [1:0] din ;
wire [1:0] din ;

always @ (din) begin
case (din)
 2'b00 : assign dout = 4'b1000;
 2'b01 : assign dout = 4'b0100;
 2'b10 : assign dout = 4'b0010;
 default : assign dout = 4'b0001;
endcase
end
endmodule

module testbench_decoder(din,dout);
input[1:0] din;
output[3:0] dout;
wire[1:0] din;
wire[3:0] dout;
assign din = 2'b10;
decoder decoder_instance(din,dout);
endmodule
