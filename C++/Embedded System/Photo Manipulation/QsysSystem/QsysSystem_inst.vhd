	component QsysSystem is
		port (
			clk_clk                                    : in    std_logic                     := 'X';             -- clk
			green_leds_external_connection_export      : out   std_logic_vector(7 downto 0);                     -- export
			keys_external_connection_export            : in    std_logic_vector(3 downto 0)  := (others => 'X'); -- export
			red_leds_external_connection_export        : out   std_logic_vector(17 downto 0);                    -- export
			reset_reset                                : in    std_logic                     := 'X';             -- reset
			sd_b_SD_cmd                                : inout std_logic                     := 'X';             -- b_SD_cmd
			sd_b_SD_dat                                : inout std_logic                     := 'X';             -- b_SD_dat
			sd_b_SD_dat3                               : inout std_logic                     := 'X';             -- b_SD_dat3
			sd_o_SD_clock                              : out   std_logic;                                        -- o_SD_clock
			sdram_clk_clk                              : out   std_logic;                                        -- clk
			sdram_wire_addr                            : out   std_logic_vector(12 downto 0);                    -- addr
			sdram_wire_ba                              : out   std_logic_vector(1 downto 0);                     -- ba
			sdram_wire_cas_n                           : out   std_logic;                                        -- cas_n
			sdram_wire_cke                             : out   std_logic;                                        -- cke
			sdram_wire_cs_n                            : out   std_logic;                                        -- cs_n
			sdram_wire_dq                              : inout std_logic_vector(31 downto 0) := (others => 'X'); -- dq
			sdram_wire_dqm                             : out   std_logic_vector(3 downto 0);                     -- dqm
			sdram_wire_ras_n                           : out   std_logic;                                        -- ras_n
			sdram_wire_we_n                            : out   std_logic;                                        -- we_n
			sevseg4msb_external_connection_export      : out   std_logic_vector(31 downto 0);                    -- export
			sevsegment_4lsb_external_connection_export : out   std_logic_vector(31 downto 0);                    -- export
			sram_DQ                                    : inout std_logic_vector(15 downto 0) := (others => 'X'); -- DQ
			sram_ADDR                                  : out   std_logic_vector(19 downto 0);                    -- ADDR
			sram_LB_N                                  : out   std_logic;                                        -- LB_N
			sram_UB_N                                  : out   std_logic;                                        -- UB_N
			sram_CE_N                                  : out   std_logic;                                        -- CE_N
			sram_OE_N                                  : out   std_logic;                                        -- OE_N
			sram_WE_N                                  : out   std_logic;                                        -- WE_N
			switches_external_connection_export        : in    std_logic_vector(17 downto 0) := (others => 'X'); -- export
			vga_out_CLK                                : out   std_logic;                                        -- CLK
			vga_out_HS                                 : out   std_logic;                                        -- HS
			vga_out_VS                                 : out   std_logic;                                        -- VS
			vga_out_BLANK                              : out   std_logic;                                        -- BLANK
			vga_out_SYNC                               : out   std_logic;                                        -- SYNC
			vga_out_R                                  : out   std_logic_vector(7 downto 0);                     -- R
			vga_out_G                                  : out   std_logic_vector(7 downto 0);                     -- G
			vga_out_B                                  : out   std_logic_vector(7 downto 0)                      -- B
		);
	end component QsysSystem;

	u0 : component QsysSystem
		port map (
			clk_clk                                    => CONNECTED_TO_clk_clk,                                    --                                 clk.clk
			green_leds_external_connection_export      => CONNECTED_TO_green_leds_external_connection_export,      --      green_leds_external_connection.export
			keys_external_connection_export            => CONNECTED_TO_keys_external_connection_export,            --            keys_external_connection.export
			red_leds_external_connection_export        => CONNECTED_TO_red_leds_external_connection_export,        --        red_leds_external_connection.export
			reset_reset                                => CONNECTED_TO_reset_reset,                                --                               reset.reset
			sd_b_SD_cmd                                => CONNECTED_TO_sd_b_SD_cmd,                                --                                  sd.b_SD_cmd
			sd_b_SD_dat                                => CONNECTED_TO_sd_b_SD_dat,                                --                                    .b_SD_dat
			sd_b_SD_dat3                               => CONNECTED_TO_sd_b_SD_dat3,                               --                                    .b_SD_dat3
			sd_o_SD_clock                              => CONNECTED_TO_sd_o_SD_clock,                              --                                    .o_SD_clock
			sdram_clk_clk                              => CONNECTED_TO_sdram_clk_clk,                              --                           sdram_clk.clk
			sdram_wire_addr                            => CONNECTED_TO_sdram_wire_addr,                            --                          sdram_wire.addr
			sdram_wire_ba                              => CONNECTED_TO_sdram_wire_ba,                              --                                    .ba
			sdram_wire_cas_n                           => CONNECTED_TO_sdram_wire_cas_n,                           --                                    .cas_n
			sdram_wire_cke                             => CONNECTED_TO_sdram_wire_cke,                             --                                    .cke
			sdram_wire_cs_n                            => CONNECTED_TO_sdram_wire_cs_n,                            --                                    .cs_n
			sdram_wire_dq                              => CONNECTED_TO_sdram_wire_dq,                              --                                    .dq
			sdram_wire_dqm                             => CONNECTED_TO_sdram_wire_dqm,                             --                                    .dqm
			sdram_wire_ras_n                           => CONNECTED_TO_sdram_wire_ras_n,                           --                                    .ras_n
			sdram_wire_we_n                            => CONNECTED_TO_sdram_wire_we_n,                            --                                    .we_n
			sevseg4msb_external_connection_export      => CONNECTED_TO_sevseg4msb_external_connection_export,      --      sevseg4msb_external_connection.export
			sevsegment_4lsb_external_connection_export => CONNECTED_TO_sevsegment_4lsb_external_connection_export, -- sevsegment_4lsb_external_connection.export
			sram_DQ                                    => CONNECTED_TO_sram_DQ,                                    --                                sram.DQ
			sram_ADDR                                  => CONNECTED_TO_sram_ADDR,                                  --                                    .ADDR
			sram_LB_N                                  => CONNECTED_TO_sram_LB_N,                                  --                                    .LB_N
			sram_UB_N                                  => CONNECTED_TO_sram_UB_N,                                  --                                    .UB_N
			sram_CE_N                                  => CONNECTED_TO_sram_CE_N,                                  --                                    .CE_N
			sram_OE_N                                  => CONNECTED_TO_sram_OE_N,                                  --                                    .OE_N
			sram_WE_N                                  => CONNECTED_TO_sram_WE_N,                                  --                                    .WE_N
			switches_external_connection_export        => CONNECTED_TO_switches_external_connection_export,        --        switches_external_connection.export
			vga_out_CLK                                => CONNECTED_TO_vga_out_CLK,                                --                             vga_out.CLK
			vga_out_HS                                 => CONNECTED_TO_vga_out_HS,                                 --                                    .HS
			vga_out_VS                                 => CONNECTED_TO_vga_out_VS,                                 --                                    .VS
			vga_out_BLANK                              => CONNECTED_TO_vga_out_BLANK,                              --                                    .BLANK
			vga_out_SYNC                               => CONNECTED_TO_vga_out_SYNC,                               --                                    .SYNC
			vga_out_R                                  => CONNECTED_TO_vga_out_R,                                  --                                    .R
			vga_out_G                                  => CONNECTED_TO_vga_out_G,                                  --                                    .G
			vga_out_B                                  => CONNECTED_TO_vga_out_B                                   --                                    .B
		);

