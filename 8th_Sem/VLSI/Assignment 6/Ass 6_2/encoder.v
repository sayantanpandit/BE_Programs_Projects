module parity_encoder ( din ,dout );

output [1:0] dout ;
reg [1:0] dout ;

input [3:0] din ;
wire [3:0] din ;


always @ (din) begin
 
 if (din[3])
  dout = 0;
 else if (din[2])
  dout = 1;
 else if (din[1])
  dout = 2;
 else if (din[0])
  dout = 3;
 else
  dout = 3'bZZZ;
end

endmodule
module testbench_encoder(din,dout);
input[3:0] din;
output[1:0] dout;
wire[3:0] din;
wire[1:0] dout;

assign din = 4'b0010;
parity_encoder encoder_instance(din,dout);

endmodule
