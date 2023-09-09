	component QsysSystem is
		port (
			clk_clk                                    : in    std_logic                     := 'X';             -- clk
			green_leds_external_connection_export      : out   std_logic_vector(7 downto 0);                     -- export
			keys_external_connection_export            : in    std_logic_vector(3 downto 0)  := (others => 'X'); -- export
			red_leds_external_connection_export        : out   std_logic_vector(17 downto 0);                    -- export
			reset_reset                                : in    std_logic                     := 'X';             -- reset
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
			switches_external_connection_export        : in    std_logic_vector(17 downto 0) := (others => 'X')  -- export
		);
	end component QsysSystem;

	u0 : component QsysSystem
		port map (
			clk_clk                                    => CONNECTED_TO_clk_clk,                                    --                                 clk.clk
			green_leds_external_connection_export      => CONNECTED_TO_green_leds_external_connection_export,      --      green_leds_external_connection.export
			keys_external_connection_export            => CONNECTED_TO_keys_external_connection_export,            --            keys_external_connection.export
			red_leds_external_connection_export        => CONNECTED_TO_red_leds_external_connection_export,        --        red_leds_external_connection.export
			reset_reset                                => CONNECTED_TO_reset_reset,                                --                               reset.reset
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
			switches_external_connection_export        => CONNECTED_TO_switches_external_connection_export         --        switches_external_connection.export
		);

