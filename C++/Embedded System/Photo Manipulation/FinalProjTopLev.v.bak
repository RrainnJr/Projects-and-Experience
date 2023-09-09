module Lab3SoftcoreDesign (CLOCK_50, SW, KEY, LEDR, LEDG, DRAM_CLK, SevMSB, SevLSB, sdram_wire_addr, sdram_wire_ba, 
sdram_wire_cas_n, sdram_wire_cke, sdram_wire_cs_n, sdram_wire_dq, sdram_wire_dqm, sdram_wire_ras_n, sdram_wire_we_n);
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
.sdram_clk_clk(DRAM_CLK));
endmodule