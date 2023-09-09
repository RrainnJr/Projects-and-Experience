// QsysSystem_VGASubsys_0_Char_Buf_Subsystem.v

// Generated using ACDS version 16.1 196

`timescale 1 ps / 1 ps
module QsysSystem_VGASubsys_0_Char_Buf_Subsystem (
		input  wire        avalon_char_source_ready,             //        avalon_char_source.ready
		output wire        avalon_char_source_startofpacket,     //                          .startofpacket
		output wire        avalon_char_source_endofpacket,       //                          .endofpacket
		output wire        avalon_char_source_valid,             //                          .valid
		output wire [39:0] avalon_char_source_data,              //                          .data
		input  wire [1:0]  char_buffer_control_slave_address,    // char_buffer_control_slave.address
		input  wire [3:0]  char_buffer_control_slave_byteenable, //                          .byteenable
		input  wire        char_buffer_control_slave_read,       //                          .read
		input  wire        char_buffer_control_slave_write,      //                          .write
		input  wire [31:0] char_buffer_control_slave_writedata,  //                          .writedata
		output wire [31:0] char_buffer_control_slave_readdata,   //                          .readdata
		input  wire [10:0] char_buffer_slave_address,            //         char_buffer_slave.address
		input  wire        char_buffer_slave_clken,              //                          .clken
		input  wire        char_buffer_slave_chipselect,         //                          .chipselect
		input  wire        char_buffer_slave_write,              //                          .write
		output wire [31:0] char_buffer_slave_readdata,           //                          .readdata
		input  wire [31:0] char_buffer_slave_writedata,          //                          .writedata
		input  wire [3:0]  char_buffer_slave_byteenable,         //                          .byteenable
		input  wire        sys_clk_clk,                          //                   sys_clk.clk
		input  wire        sys_reset_reset_n                     //                 sys_reset.reset_n
	);

	wire         ascii_to_image_avalon_image_source_valid;               // ASCII_to_Image:image_out_valid -> Char_Buf_RGB_Resampler:stream_in_valid
	wire         ascii_to_image_avalon_image_source_data;                // ASCII_to_Image:image_out_data -> Char_Buf_RGB_Resampler:stream_in_data
	wire         ascii_to_image_avalon_image_source_ready;               // Char_Buf_RGB_Resampler:stream_in_ready -> ASCII_to_Image:image_out_ready
	wire         ascii_to_image_avalon_image_source_startofpacket;       // ASCII_to_Image:image_out_startofpacket -> Char_Buf_RGB_Resampler:stream_in_startofpacket
	wire         ascii_to_image_avalon_image_source_endofpacket;         // ASCII_to_Image:image_out_endofpacket -> Char_Buf_RGB_Resampler:stream_in_endofpacket
	wire         char_buf_dma_avalon_pixel_source_valid;                 // Char_Buf_DMA:stream_valid -> Char_Buf_Scaler:stream_in_valid
	wire   [7:0] char_buf_dma_avalon_pixel_source_data;                  // Char_Buf_DMA:stream_data -> Char_Buf_Scaler:stream_in_data
	wire         char_buf_dma_avalon_pixel_source_ready;                 // Char_Buf_Scaler:stream_in_ready -> Char_Buf_DMA:stream_ready
	wire         char_buf_dma_avalon_pixel_source_startofpacket;         // Char_Buf_DMA:stream_startofpacket -> Char_Buf_Scaler:stream_in_startofpacket
	wire         char_buf_dma_avalon_pixel_source_endofpacket;           // Char_Buf_DMA:stream_endofpacket -> Char_Buf_Scaler:stream_in_endofpacket
	wire         char_buf_rgb_resampler_avalon_rgb_source_valid;         // Char_Buf_RGB_Resampler:stream_out_valid -> Set_Black_Transparent:stream_in_valid
	wire  [39:0] char_buf_rgb_resampler_avalon_rgb_source_data;          // Char_Buf_RGB_Resampler:stream_out_data -> Set_Black_Transparent:stream_in_data
	wire         char_buf_rgb_resampler_avalon_rgb_source_ready;         // Set_Black_Transparent:stream_in_ready -> Char_Buf_RGB_Resampler:stream_out_ready
	wire         char_buf_rgb_resampler_avalon_rgb_source_startofpacket; // Char_Buf_RGB_Resampler:stream_out_startofpacket -> Set_Black_Transparent:stream_in_startofpacket
	wire         char_buf_rgb_resampler_avalon_rgb_source_endofpacket;   // Char_Buf_RGB_Resampler:stream_out_endofpacket -> Set_Black_Transparent:stream_in_endofpacket
	wire         char_buf_scaler_avalon_scaler_source_valid;             // Char_Buf_Scaler:stream_out_valid -> ASCII_to_Image:ascii_in_valid
	wire   [7:0] char_buf_scaler_avalon_scaler_source_data;              // Char_Buf_Scaler:stream_out_data -> ASCII_to_Image:ascii_in_data
	wire         char_buf_scaler_avalon_scaler_source_ready;             // ASCII_to_Image:ascii_in_ready -> Char_Buf_Scaler:stream_out_ready
	wire   [5:0] char_buf_scaler_avalon_scaler_source_channel;           // Char_Buf_Scaler:stream_out_channel -> ASCII_to_Image:ascii_in_channel
	wire         char_buf_scaler_avalon_scaler_source_startofpacket;     // Char_Buf_Scaler:stream_out_startofpacket -> ASCII_to_Image:ascii_in_startofpacket
	wire         char_buf_scaler_avalon_scaler_source_endofpacket;       // Char_Buf_Scaler:stream_out_endofpacket -> ASCII_to_Image:ascii_in_endofpacket
	wire         char_buf_dma_avalon_dma_master_waitrequest;             // mm_interconnect_0:Char_Buf_DMA_avalon_dma_master_waitrequest -> Char_Buf_DMA:master_waitrequest
	wire   [7:0] char_buf_dma_avalon_dma_master_readdata;                // mm_interconnect_0:Char_Buf_DMA_avalon_dma_master_readdata -> Char_Buf_DMA:master_readdata
	wire  [31:0] char_buf_dma_avalon_dma_master_address;                 // Char_Buf_DMA:master_address -> mm_interconnect_0:Char_Buf_DMA_avalon_dma_master_address
	wire         char_buf_dma_avalon_dma_master_read;                    // Char_Buf_DMA:master_read -> mm_interconnect_0:Char_Buf_DMA_avalon_dma_master_read
	wire         char_buf_dma_avalon_dma_master_readdatavalid;           // mm_interconnect_0:Char_Buf_DMA_avalon_dma_master_readdatavalid -> Char_Buf_DMA:master_readdatavalid
	wire         char_buf_dma_avalon_dma_master_lock;                    // Char_Buf_DMA:master_arbiterlock -> mm_interconnect_0:Char_Buf_DMA_avalon_dma_master_lock
	wire         mm_interconnect_0_onchip_sram_s2_chipselect;            // mm_interconnect_0:Onchip_SRAM_s2_chipselect -> Onchip_SRAM:chipselect2
	wire  [31:0] mm_interconnect_0_onchip_sram_s2_readdata;              // Onchip_SRAM:readdata2 -> mm_interconnect_0:Onchip_SRAM_s2_readdata
	wire  [10:0] mm_interconnect_0_onchip_sram_s2_address;               // mm_interconnect_0:Onchip_SRAM_s2_address -> Onchip_SRAM:address2
	wire   [3:0] mm_interconnect_0_onchip_sram_s2_byteenable;            // mm_interconnect_0:Onchip_SRAM_s2_byteenable -> Onchip_SRAM:byteenable2
	wire         mm_interconnect_0_onchip_sram_s2_write;                 // mm_interconnect_0:Onchip_SRAM_s2_write -> Onchip_SRAM:write2
	wire  [31:0] mm_interconnect_0_onchip_sram_s2_writedata;             // mm_interconnect_0:Onchip_SRAM_s2_writedata -> Onchip_SRAM:writedata2
	wire         mm_interconnect_0_onchip_sram_s2_clken;                 // mm_interconnect_0:Onchip_SRAM_s2_clken -> Onchip_SRAM:clken2
	wire         rst_controller_reset_out_reset;                         // rst_controller:reset_out -> [ASCII_to_Image:reset, Char_Buf_DMA:reset, Char_Buf_RGB_Resampler:reset, Char_Buf_Scaler:reset, Onchip_SRAM:reset, Set_Black_Transparent:reset, mm_interconnect_0:Char_Buf_DMA_reset_reset_bridge_in_reset_reset, rst_translator:in_reset]
	wire         rst_controller_reset_out_reset_req;                     // rst_controller:reset_req -> [Onchip_SRAM:reset_req, rst_translator:reset_req_in]

	QsysSystem_VGASubsys_0_Char_Buf_Subsystem_ASCII_to_Image ascii_to_image (
		.clk                     (sys_clk_clk),                                        //                 clk.clk
		.reset                   (rst_controller_reset_out_reset),                     //               reset.reset
		.ascii_in_channel        (char_buf_scaler_avalon_scaler_source_channel),       //   avalon_ascii_sink.channel
		.ascii_in_startofpacket  (char_buf_scaler_avalon_scaler_source_startofpacket), //                    .startofpacket
		.ascii_in_endofpacket    (char_buf_scaler_avalon_scaler_source_endofpacket),   //                    .endofpacket
		.ascii_in_valid          (char_buf_scaler_avalon_scaler_source_valid),         //                    .valid
		.ascii_in_ready          (char_buf_scaler_avalon_scaler_source_ready),         //                    .ready
		.ascii_in_data           (char_buf_scaler_avalon_scaler_source_data),          //                    .data
		.image_out_ready         (ascii_to_image_avalon_image_source_ready),           // avalon_image_source.ready
		.image_out_startofpacket (ascii_to_image_avalon_image_source_startofpacket),   //                    .startofpacket
		.image_out_endofpacket   (ascii_to_image_avalon_image_source_endofpacket),     //                    .endofpacket
		.image_out_valid         (ascii_to_image_avalon_image_source_valid),           //                    .valid
		.image_out_data          (ascii_to_image_avalon_image_source_data)             //                    .data
	);

	QsysSystem_VGASubsys_0_Char_Buf_Subsystem_Char_Buf_DMA char_buf_dma (
		.clk                  (sys_clk_clk),                                    //                      clk.clk
		.reset                (rst_controller_reset_out_reset),                 //                    reset.reset
		.master_address       (char_buf_dma_avalon_dma_master_address),         //        avalon_dma_master.address
		.master_waitrequest   (char_buf_dma_avalon_dma_master_waitrequest),     //                         .waitrequest
		.master_arbiterlock   (char_buf_dma_avalon_dma_master_lock),            //                         .lock
		.master_read          (char_buf_dma_avalon_dma_master_read),            //                         .read
		.master_readdata      (char_buf_dma_avalon_dma_master_readdata),        //                         .readdata
		.master_readdatavalid (char_buf_dma_avalon_dma_master_readdatavalid),   //                         .readdatavalid
		.slave_address        (char_buffer_control_slave_address),              // avalon_dma_control_slave.address
		.slave_byteenable     (char_buffer_control_slave_byteenable),           //                         .byteenable
		.slave_read           (char_buffer_control_slave_read),                 //                         .read
		.slave_write          (char_buffer_control_slave_write),                //                         .write
		.slave_writedata      (char_buffer_control_slave_writedata),            //                         .writedata
		.slave_readdata       (char_buffer_control_slave_readdata),             //                         .readdata
		.stream_ready         (char_buf_dma_avalon_pixel_source_ready),         //      avalon_pixel_source.ready
		.stream_data          (char_buf_dma_avalon_pixel_source_data),          //                         .data
		.stream_startofpacket (char_buf_dma_avalon_pixel_source_startofpacket), //                         .startofpacket
		.stream_endofpacket   (char_buf_dma_avalon_pixel_source_endofpacket),   //                         .endofpacket
		.stream_valid         (char_buf_dma_avalon_pixel_source_valid)          //                         .valid
	);

	QsysSystem_VGASubsys_0_Char_Buf_Subsystem_Char_Buf_RGB_Resampler char_buf_rgb_resampler (
		.clk                      (sys_clk_clk),                                            //               clk.clk
		.reset                    (rst_controller_reset_out_reset),                         //             reset.reset
		.stream_in_startofpacket  (ascii_to_image_avalon_image_source_startofpacket),       //   avalon_rgb_sink.startofpacket
		.stream_in_endofpacket    (ascii_to_image_avalon_image_source_endofpacket),         //                  .endofpacket
		.stream_in_valid          (ascii_to_image_avalon_image_source_valid),               //                  .valid
		.stream_in_ready          (ascii_to_image_avalon_image_source_ready),               //                  .ready
		.stream_in_data           (ascii_to_image_avalon_image_source_data),                //                  .data
		.stream_out_ready         (char_buf_rgb_resampler_avalon_rgb_source_ready),         // avalon_rgb_source.ready
		.stream_out_startofpacket (char_buf_rgb_resampler_avalon_rgb_source_startofpacket), //                  .startofpacket
		.stream_out_endofpacket   (char_buf_rgb_resampler_avalon_rgb_source_endofpacket),   //                  .endofpacket
		.stream_out_valid         (char_buf_rgb_resampler_avalon_rgb_source_valid),         //                  .valid
		.stream_out_data          (char_buf_rgb_resampler_avalon_rgb_source_data)           //                  .data
	);

	QsysSystem_VGASubsys_0_Char_Buf_Subsystem_Char_Buf_Scaler char_buf_scaler (
		.clk                      (sys_clk_clk),                                        //                  clk.clk
		.reset                    (rst_controller_reset_out_reset),                     //                reset.reset
		.stream_in_startofpacket  (char_buf_dma_avalon_pixel_source_startofpacket),     //   avalon_scaler_sink.startofpacket
		.stream_in_endofpacket    (char_buf_dma_avalon_pixel_source_endofpacket),       //                     .endofpacket
		.stream_in_valid          (char_buf_dma_avalon_pixel_source_valid),             //                     .valid
		.stream_in_ready          (char_buf_dma_avalon_pixel_source_ready),             //                     .ready
		.stream_in_data           (char_buf_dma_avalon_pixel_source_data),              //                     .data
		.stream_out_ready         (char_buf_scaler_avalon_scaler_source_ready),         // avalon_scaler_source.ready
		.stream_out_startofpacket (char_buf_scaler_avalon_scaler_source_startofpacket), //                     .startofpacket
		.stream_out_endofpacket   (char_buf_scaler_avalon_scaler_source_endofpacket),   //                     .endofpacket
		.stream_out_valid         (char_buf_scaler_avalon_scaler_source_valid),         //                     .valid
		.stream_out_data          (char_buf_scaler_avalon_scaler_source_data),          //                     .data
		.stream_out_channel       (char_buf_scaler_avalon_scaler_source_channel)        //                     .channel
	);

	QsysSystem_VGASubsys_0_Char_Buf_Subsystem_Onchip_SRAM onchip_sram (
		.address     (char_buffer_slave_address),                   //     s1.address
		.clken       (char_buffer_slave_clken),                     //       .clken
		.chipselect  (char_buffer_slave_chipselect),                //       .chipselect
		.write       (char_buffer_slave_write),                     //       .write
		.readdata    (char_buffer_slave_readdata),                  //       .readdata
		.writedata   (char_buffer_slave_writedata),                 //       .writedata
		.byteenable  (char_buffer_slave_byteenable),                //       .byteenable
		.address2    (mm_interconnect_0_onchip_sram_s2_address),    //     s2.address
		.chipselect2 (mm_interconnect_0_onchip_sram_s2_chipselect), //       .chipselect
		.clken2      (mm_interconnect_0_onchip_sram_s2_clken),      //       .clken
		.write2      (mm_interconnect_0_onchip_sram_s2_write),      //       .write
		.readdata2   (mm_interconnect_0_onchip_sram_s2_readdata),   //       .readdata
		.writedata2  (mm_interconnect_0_onchip_sram_s2_writedata),  //       .writedata
		.byteenable2 (mm_interconnect_0_onchip_sram_s2_byteenable), //       .byteenable
		.clk         (sys_clk_clk),                                 //   clk1.clk
		.reset       (rst_controller_reset_out_reset),              // reset1.reset
		.reset_req   (rst_controller_reset_out_reset_req),          //       .reset_req
		.freeze      (1'b0)                                         // (terminated)
	);

	QsysSystem_VGASubsys_0_Char_Buf_Subsystem_Set_Black_Transparent set_black_transparent (
		.clk                      (sys_clk_clk),                                            //                       clk.clk
		.reset                    (rst_controller_reset_out_reset),                         //                     reset.reset
		.stream_in_startofpacket  (char_buf_rgb_resampler_avalon_rgb_source_startofpacket), //   avalon_apply_alpha_sink.startofpacket
		.stream_in_endofpacket    (char_buf_rgb_resampler_avalon_rgb_source_endofpacket),   //                          .endofpacket
		.stream_in_valid          (char_buf_rgb_resampler_avalon_rgb_source_valid),         //                          .valid
		.stream_in_ready          (char_buf_rgb_resampler_avalon_rgb_source_ready),         //                          .ready
		.stream_in_data           (char_buf_rgb_resampler_avalon_rgb_source_data),          //                          .data
		.stream_out_ready         (avalon_char_source_ready),                               // avalon_apply_alpha_source.ready
		.stream_out_startofpacket (avalon_char_source_startofpacket),                       //                          .startofpacket
		.stream_out_endofpacket   (avalon_char_source_endofpacket),                         //                          .endofpacket
		.stream_out_valid         (avalon_char_source_valid),                               //                          .valid
		.stream_out_data          (avalon_char_source_data)                                 //                          .data
	);

	QsysSystem_VGASubsys_0_Char_Buf_Subsystem_mm_interconnect_0 mm_interconnect_0 (
		.Sys_Clk_clk_clk                                (sys_clk_clk),                                  //                              Sys_Clk_clk.clk
		.Char_Buf_DMA_reset_reset_bridge_in_reset_reset (rst_controller_reset_out_reset),               // Char_Buf_DMA_reset_reset_bridge_in_reset.reset
		.Char_Buf_DMA_avalon_dma_master_address         (char_buf_dma_avalon_dma_master_address),       //           Char_Buf_DMA_avalon_dma_master.address
		.Char_Buf_DMA_avalon_dma_master_waitrequest     (char_buf_dma_avalon_dma_master_waitrequest),   //                                         .waitrequest
		.Char_Buf_DMA_avalon_dma_master_read            (char_buf_dma_avalon_dma_master_read),          //                                         .read
		.Char_Buf_DMA_avalon_dma_master_readdata        (char_buf_dma_avalon_dma_master_readdata),      //                                         .readdata
		.Char_Buf_DMA_avalon_dma_master_readdatavalid   (char_buf_dma_avalon_dma_master_readdatavalid), //                                         .readdatavalid
		.Char_Buf_DMA_avalon_dma_master_lock            (char_buf_dma_avalon_dma_master_lock),          //                                         .lock
		.Onchip_SRAM_s2_address                         (mm_interconnect_0_onchip_sram_s2_address),     //                           Onchip_SRAM_s2.address
		.Onchip_SRAM_s2_write                           (mm_interconnect_0_onchip_sram_s2_write),       //                                         .write
		.Onchip_SRAM_s2_readdata                        (mm_interconnect_0_onchip_sram_s2_readdata),    //                                         .readdata
		.Onchip_SRAM_s2_writedata                       (mm_interconnect_0_onchip_sram_s2_writedata),   //                                         .writedata
		.Onchip_SRAM_s2_byteenable                      (mm_interconnect_0_onchip_sram_s2_byteenable),  //                                         .byteenable
		.Onchip_SRAM_s2_chipselect                      (mm_interconnect_0_onchip_sram_s2_chipselect),  //                                         .chipselect
		.Onchip_SRAM_s2_clken                           (mm_interconnect_0_onchip_sram_s2_clken)        //                                         .clken
	);

	altera_reset_controller #(
		.NUM_RESET_INPUTS          (1),
		.OUTPUT_RESET_SYNC_EDGES   ("deassert"),
		.SYNC_DEPTH                (2),
		.RESET_REQUEST_PRESENT     (1),
		.RESET_REQ_WAIT_TIME       (1),
		.MIN_RST_ASSERTION_TIME    (3),
		.RESET_REQ_EARLY_DSRT_TIME (1),
		.USE_RESET_REQUEST_IN0     (0),
		.USE_RESET_REQUEST_IN1     (0),
		.USE_RESET_REQUEST_IN2     (0),
		.USE_RESET_REQUEST_IN3     (0),
		.USE_RESET_REQUEST_IN4     (0),
		.USE_RESET_REQUEST_IN5     (0),
		.USE_RESET_REQUEST_IN6     (0),
		.USE_RESET_REQUEST_IN7     (0),
		.USE_RESET_REQUEST_IN8     (0),
		.USE_RESET_REQUEST_IN9     (0),
		.USE_RESET_REQUEST_IN10    (0),
		.USE_RESET_REQUEST_IN11    (0),
		.USE_RESET_REQUEST_IN12    (0),
		.USE_RESET_REQUEST_IN13    (0),
		.USE_RESET_REQUEST_IN14    (0),
		.USE_RESET_REQUEST_IN15    (0),
		.ADAPT_RESET_REQUEST       (0)
	) rst_controller (
		.reset_in0      (~sys_reset_reset_n),                 // reset_in0.reset
		.clk            (sys_clk_clk),                        //       clk.clk
		.reset_out      (rst_controller_reset_out_reset),     // reset_out.reset
		.reset_req      (rst_controller_reset_out_reset_req), //          .reset_req
		.reset_req_in0  (1'b0),                               // (terminated)
		.reset_in1      (1'b0),                               // (terminated)
		.reset_req_in1  (1'b0),                               // (terminated)
		.reset_in2      (1'b0),                               // (terminated)
		.reset_req_in2  (1'b0),                               // (terminated)
		.reset_in3      (1'b0),                               // (terminated)
		.reset_req_in3  (1'b0),                               // (terminated)
		.reset_in4      (1'b0),                               // (terminated)
		.reset_req_in4  (1'b0),                               // (terminated)
		.reset_in5      (1'b0),                               // (terminated)
		.reset_req_in5  (1'b0),                               // (terminated)
		.reset_in6      (1'b0),                               // (terminated)
		.reset_req_in6  (1'b0),                               // (terminated)
		.reset_in7      (1'b0),                               // (terminated)
		.reset_req_in7  (1'b0),                               // (terminated)
		.reset_in8      (1'b0),                               // (terminated)
		.reset_req_in8  (1'b0),                               // (terminated)
		.reset_in9      (1'b0),                               // (terminated)
		.reset_req_in9  (1'b0),                               // (terminated)
		.reset_in10     (1'b0),                               // (terminated)
		.reset_req_in10 (1'b0),                               // (terminated)
		.reset_in11     (1'b0),                               // (terminated)
		.reset_req_in11 (1'b0),                               // (terminated)
		.reset_in12     (1'b0),                               // (terminated)
		.reset_req_in12 (1'b0),                               // (terminated)
		.reset_in13     (1'b0),                               // (terminated)
		.reset_req_in13 (1'b0),                               // (terminated)
		.reset_in14     (1'b0),                               // (terminated)
		.reset_req_in14 (1'b0),                               // (terminated)
		.reset_in15     (1'b0),                               // (terminated)
		.reset_req_in15 (1'b0)                                // (terminated)
	);

endmodule
