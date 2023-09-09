
module QsysSystem (
	clk_clk,
	green_leds_external_connection_export,
	keys_external_connection_export,
	red_leds_external_connection_export,
	reset_reset,
	sd_b_SD_cmd,
	sd_b_SD_dat,
	sd_b_SD_dat3,
	sd_o_SD_clock,
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
	sram_DQ,
	sram_ADDR,
	sram_LB_N,
	sram_UB_N,
	sram_CE_N,
	sram_OE_N,
	sram_WE_N,
	switches_external_connection_export,
	vga_out_CLK,
	vga_out_HS,
	vga_out_VS,
	vga_out_BLANK,
	vga_out_SYNC,
	vga_out_R,
	vga_out_G,
	vga_out_B);	

	input		clk_clk;
	output	[7:0]	green_leds_external_connection_export;
	input	[3:0]	keys_external_connection_export;
	output	[17:0]	red_leds_external_connection_export;
	input		reset_reset;
	inout		sd_b_SD_cmd;
	inout		sd_b_SD_dat;
	inout		sd_b_SD_dat3;
	output		sd_o_SD_clock;
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
	inout	[15:0]	sram_DQ;
	output	[19:0]	sram_ADDR;
	output		sram_LB_N;
	output		sram_UB_N;
	output		sram_CE_N;
	output		sram_OE_N;
	output		sram_WE_N;
	input	[17:0]	switches_external_connection_export;
	output		vga_out_CLK;
	output		vga_out_HS;
	output		vga_out_VS;
	output		vga_out_BLANK;
	output		vga_out_SYNC;
	output	[7:0]	vga_out_R;
	output	[7:0]	vga_out_G;
	output	[7:0]	vga_out_B;
endmodule
