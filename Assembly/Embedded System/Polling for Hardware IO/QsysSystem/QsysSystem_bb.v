
module QsysSystem (
	clk_clk,
	green_leds_external_connection_export,
	keys_external_connection_export,
	red_leds_external_connection_export,
	reset_reset,
	sdram_clk_clk,
	sdram_wire_addr,
	sdram_wire_ba,
	sdram_wire_cas_n,
	sdram_wire_cke,
	sdram_wire_cs_n,
	sdram_wire_dq,
	sdram_wire_dqm,
	sdram_wire_ras_n,
	sdram_wire_we_n,
	sevseg4msb_external_connection_export,
	sevsegment_4lsb_external_connection_export,
	switches_external_connection_export);	

	input		clk_clk;
	output	[7:0]	green_leds_external_connection_export;
	input	[3:0]	keys_external_connection_export;
	output	[17:0]	red_leds_external_connection_export;
	input		reset_reset;
	output		sdram_clk_clk;
	output	[12:0]	sdram_wire_addr;
	output	[1:0]	sdram_wire_ba;
	output		sdram_wire_cas_n;
	output		sdram_wire_cke;
	output		sdram_wire_cs_n;
	inout	[31:0]	sdram_wire_dq;
	output	[3:0]	sdram_wire_dqm;
	output		sdram_wire_ras_n;
	output		sdram_wire_we_n;
	output	[31:0]	sevseg4msb_external_connection_export;
	output	[31:0]	sevsegment_4lsb_external_connection_export;
	input	[17:0]	switches_external_connection_export;
endmodule
