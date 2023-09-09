module FinalProject (CLOCK_50, SW, KEY, LEDR, LEDG, DRAM_CLK, SevMSB, SevLSB, sdram_wire_addr, sdram_wire_ba, 
sdram_wire_cas_n, sdram_wire_cke, sdram_wire_cs_n, sdram_wire_dq, sdram_wire_dqm, sdram_wire_ras_n, sdram_wire_we_n, 
SD_CMD, SD_CLK, SD_DAT, SD_DAT3, sram_DQ, sram_ADDR, sram_LB_N, sram_UB_N, 
sram_CE_N, sram_OE_N, sram_WE_N, vga_out_CLK, vga_out_HS, vga_out_VS, vga_out_BLANK, vga_out_SYNC, vga_out_R,vga_out_G,
vga_out_B);

input CLOCK_50;
input [17:0] SW;
input [3:0] KEY;
output [7:0] LEDG;
output [17:0] LEDR;
output [31:0] SevMSB;
output [31:0] SevLSB;
output [12:0] sdram_wire_addr;                    
output [1:0]  sdram_wire_ba;                             
output sdram_wire_cas_n;                         
output sdram_wire_cke;                             
output sdram_wire_cs_n;                           
inout  [31:0] sdram_wire_dq;
output DRAM_CLK;
output [3:0] sdram_wire_dqm;                           
output sdram_wire_ras_n;                           
output sdram_wire_we_n;
output SD_CLK;
inout SD_CMD;
inout SD_DAT;
inout SD_DAT3;
inout [15:0] sram_DQ;
output [19:0] sram_ADDR;
output sram_LB_N;
output sram_UB_N;
output sram_CE_N;
output sram_OE_N;
output sram_WE_N;
output vga_out_CLK;
output vga_out_HS;
output vga_out_VS;
output vga_out_BLANK;
output vga_out_SYNC;
output [7:0]  vga_out_R;                           
output [7:0]  vga_out_G;                                  
output [7:0]  vga_out_B; 

QsysSystem Softcore (
.clk_clk(CLOCK_50),
.reset_reset(),
.green_leds_external_connection_export(LEDG),
.red_leds_external_connection_export(LEDR),
.switches_external_connection_export(SW),
.sevseg4msb_external_connection_export(SevMSB),
.sevsegment_4lsb_external_connection_export(SevLSB),
.keys_external_connection_export(KEY),
.sdram_wire_addr(sdram_wire_addr),                    
.sdram_wire_ba(sdram_wire_ba),                             
.sdram_wire_cas_n(sdram_wire_cas_n),                         
.sdram_wire_cke(sdram_wire_cke),                             
.sdram_wire_cs_n(sdram_wire_cs_n),                           
.sdram_wire_dq(sdram_wire_dq),                              
.sdram_wire_dqm(sdram_wire_dqm),                             
.sdram_wire_ras_n(sdram_wire_ras_n),                           
.sdram_wire_we_n(sdram_wire_we_n),
.sd_b_SD_cmd(SD_CMD), 
.sd_b_SD_dat(SD_DAT),
.sd_b_SD_dat3(SD_DAT3),
.sd_o_SD_clock(SD_CLK),
.sram_DQ(sram_DQ),
.sram_ADDR(sram_ADDR),
.sram_LB_N(SRAM_LB_N),
.sram_UB_N(sram_UB_N),
.sram_CE_N(sram_CE_N),
.sram_OE_N(sram_OE_N),
.sram_WE_N(sram_WE_N),
.vga_out_CLK(vga_out_CLK),
.vga_out_HS(vga_out_HS),
.vga_out_VS(vga_out_VS),
.vga_out_BLANK(vga_out_BLANK),
.vga_out_SYNC(vga_out_SYNC),
.vga_out_R(vga_out_R),
.vga_out_G(vga_out_G),
.vga_out_B(vga_out_B),
.sdram_clk_clk(DRAM_CLK));
 
endmodule