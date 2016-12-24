//-----------------------------------------------------------Crosshairs
// normal crosshair
alias nc1 "cl_crosshair_drawoutline 0"
alias nc2 "cl_crosshair_dynamic_maxdist_splitratio 0.6"
alias nc3 "cl_crosshair_dynamic_splitalpha_innermod 1"
alias nc4 "cl_crosshair_dynamic_splitalpha_outermod 0.5"
alias nc5 "cl_crosshair_dynamic_splitdist -5.5"
alias nc6 "cl_crosshair_outlinethickness 3"
alias nc7 "cl_crosshairalpha 250"
alias nc8 "cl_crosshaircolor 5" 
alias nc9 "cl_crosshaircolor_b 0"
alias nc10 "cl_crosshaircolor_g 255"
alias nc11 "cl_crosshaircolor_r 0"
alias nc12 "cl_crosshairdot 0"
alias nc13 "cl_crosshairgap -1"
alias nc14 "cl_crosshairgap_useweaponvalue 0"
alias nc15 "cl_crosshairscale 0"
alias nc16 "cl_crosshairsize 6.5"
alias nc17 "cl_crosshairstyle 2"
alias nc18 "cl_crosshairthickness 1"
alias nc19 "cl_crosshairusealpha 1"
alias nc20 "cl_fixedcrosshairgap 3"
alias ncAll "nc1; nc2; nc3; nc4; nc5; nc6; nc7; nc8; nc9; nc10; nc11; nc12; nc13; nc14; nc15; nc16; nc17; nc18; nc19; nc20;"

// smoke crosshair
alias sc1 "cl_crosshair_drawoutline 0"
alias sc2 "cl_crosshair_dynamic_maxdist_splitratio 0"
alias sc3 "cl_crosshair_dynamic_splitalpha_innermod 1"
alias sc4 "cl_crosshair_dynamic_splitalpha_outermod 0.3"
alias sc5 "cl_crosshair_dynamic_splitdist 5"
alias sc6 "cl_crosshair_outlinethickness 1"
alias sc7 "cl_crosshairalpha 150"
alias sc8 "cl_crosshaircolor 5"
alias sc9 "cl_crosshaircolor_b 0"
alias sc10 "cl_crosshaircolor_g 255"
alias sc11 "cl_crosshaircolor_r 0"
alias sc12 "cl_crosshairdot 1"
alias sc13 "cl_crosshairgap -7"
alias sc14 "cl_crosshairgap_useweaponvalue 0"
alias sc15 "cl_crosshairscale 0"
alias sc16 "cl_crosshairsize 1000"
alias sc17 "cl_crosshairstyle 4"
alias sc18 "cl_crosshairthickness 1"
alias sc19 "cl_crosshairusealpha 1"
alias sc20 "cl_fixedcrosshairgap -7"
alias scAll "sc1; sc2; sc3; sc4; sc5; sc6; sc7; sc8; sc9; sc10; sc11; sc12; sc13; sc14; sc15; sc16; sc17; sc18; sc19; sc20;"

alias NormalCrosshair "ncAll;"
alias SmokeCrosshair "scAll;"

//-----------------------------------------------------------Crosshair Binds
// take out smoke
alias TakeOutSmoke "use weapon_smokegrenade; SmokeCrosshair; BindGunQ;"

bind KP_INS "NormalCrosshair;"
bind KP_END "TakeOutSmoke;"

//-----------------------------------------------------------Altered CS:GO binds
alias CrosshairAndBindKnifeQ "NormalCrosshair; BindKnifeQ;"
alias CrosshairAndBindGunQ "NormalCrosshair; BindGunQ;"

alias CustomSlot1 "slot1; CrosshairAndBindKnifeQ;"
alias CustomSlot2 "slot2; CrosshairAndBindKnifeQ;"
alias CustomSlot3 "use weapon_knife; CrosshairAndBindGunQ; +lookatweapon" //extra swag
alias CustomSlot4 "slot4; CrosshairAndBindGunQ;"
alias CustomSlot5 "slot5; CrosshairAndBindGunQ;"

bind 1 CustomSlot1
bind 2 CustomSlot2
bind 3 CustomSlot3
bind 4 CustomSlot4
bind 5 CustomSlot5

//----------------------------------------------------------------------------------
//----------------------------------------------------------------My Custom Settings
//----------------------------------------------------------------------------------
//hud
hud_showtargetid 1

//-----------------------------------------------------aliases
//------------------------------------knife
alias CustomLastInv "CustomSlot2; CustomSlot1;"

alias BindKnifeQ "bind q UseKnife;"
alias BindGunQ "bind q UseGun;"
alias UseKnife "CustomSlot3; BindGunQ;"
alias UseGun "CustomLastInv; BindKnifeQ;"

alias +KnifeAttack "CustomSlot3; +attack2;"
alias -KnifeAttack "-attack2; CustomLastInv;"

//------------------------------------Jump
alias +JumpCrouch "+jump; +duck;"
alias -JumpCrouch "-jump; -duck;"

//------------------------------------Grenades
alias altE1 "use weapon_molotov; use weapon_incgrenade; NormalCrosshair; BindGunQ;"
alias altE "bind e altE1"

alias alt11 "use weapon_hegrenade; NormalCrosshair; BindGunQ;"
alias alt1 "bind 1 alt11"

alias alt22 "use weapon_flashbang; NormalCrosshair; BindGunQ;"
alias alt2 "bind 2 alt22"

alias alt33 TakeOutSmoke
alias alt3 "bind 3 alt33"

alias alt44 "use weapon_decoy; NormalCrosshair; BindGunQ;"
alias alt4 "bind 4 alt44"

alias defE "bind e +use"
alias def1 "bind 1 CustomSlot1"
alias def2 "bind 2 CustomSlot2"
alias def3 "bind 3 CustomSlot3"
alias def4 "bind 4 CustomSlot4"
alias +GrenadeBinds "alte; alt1; alt2; alt3; alt4"
alias -GrenadeBinds "defE; def1; def2; def3; def4"

alias +MouseModifier "CustomSlot2; +GrenadeBinds;"
alias -MouseModifier "-GrenadeBinds;"

//------------------------------------Show crosshair Settings
alias "a1" clear
alias "a2" echo ---------------------------------------------
alias "a3" echo CROSSHAIR SETTINGS
alias "a4" echo ---------------------------------------------
alias "a5" developer 2
alias "a6" con_filter_enable 1
alias "a7" con_filter_text cl_crosshair
alias "a8" host_writeconfig
alias "a9" con_filter_text cl_fix
alias "a10" host_writeconfig
alias "a11" developer 0
alias "a12" con_filter_enable 0
alias "a13" showconsole
alias "showcrosshair" "a1;a2;a3;a4;a5;a6;a7;a8;a9;a10;a11;a12;a13"

//------------------------------------Show viewmodel Settings
alias "b1" clear
alias "b2" echo ---------------------------------------------
alias "b3" echo VIEWMODEL SETTINGS
alias "b4" echo ---------------------------------------------
alias "b5" developer 2
alias "b6" con_filter_enable 1
alias "b7" con_filter_text viewmodel
alias "b8" host_writeconfig
alias "b9" con_filter_text view_punch
alias "b10" host_writeconfig
alias "b11" developer 0
alias "b12" con_filter_enable 0
alias "b13" showconsole
alias showviewmodel "b1;b2;b3;b4;b5;b6;b7;b8;b9;b10;b11;b12;b13"
bind pgup showviewmodel

//------------------------------------Display Damage
alias displaydamage_on "con_filter_text Damage Given To; con_filter_text_out Player:; con_filter_enable 2; developer 1;"
displaydamage_on

//------------------------------------Show netgraph when checking scoreboard
net_graph "1"
net_graphheight "9999"
alias "+ScoreNet" "+showscores; net_graphheight 0"
alias "-ScoreNet" "-showscores; net_graphheight 9999"

//------------------------------------Voice
alias BindVoiceOn "bind pgdn VoiceOn"
alias BindVoiceOff "bind pgdn VoiceOff"
alias VoiceOn "sv_voiceenable 1; playvol buttons\blip1 0.5; BindVoiceOff;"
alias VoiceOff "sv_voiceenable 0; playvol buttons\blip2 0.5; BindVoiceOn;"
sv_voiceenable 0;
bind pgdn VoiceOn;

//------------------------------------------------------------buy menus
// rifles
alias buy_sg "buy sg556; give weapon_sg556;"
alias buy_ak "buy ak47; give weapon_ak47;"
alias buy_famas "buy famas; give weapon_famas;"
alias buy_awp "buy awp; give weapon_awp;"
alias buy_scout "buy scout; give weapon_scout;"
alias buy_autosniper "buy scar20; give weapon_scar20;"

// smgs
alias buy_p90 "buy p90; give weapon_p90;"
alias buy_mp7 "buy mp7; give weapon_mp7;"
alias buy_ump45 "buy ump45; give weapon_ump45;"

// pistols
alias buy_deagle "buy deagle; give weapon_deagle;"
alias buy_tec9 "buy tec9; give weapon_tec9;"
alias buy_p250 "buy p250; give weapon_p250;"

// grenades
alias buy_hegrenade "buy hegrenade; give weapon_hegrenade;"
alias buy_flashbang "buy flashbang; give weapon_flashbang;"
alias buy_smoke "buy smokegrenade; give weapon_smokegrenade;"
alias buy_molotov "buy molotov; buy incgrenade; give weapon_molotov; give weapon_incgrenade;"
alias buy_decoy "buy decoy; give weapon_decoy;"

// armor
alias buy_vesthelm "buy vesthelm;"
alias buy_vest "buy vest;"

// misc
alias buy_defuser "buy defuser;"

// multiple buys w/ one key
alias FullBuySG "buy_sg; buy_vesthelm; buy_hegrenade; buy_flashbang; buy_flashbang; buy_smoke; buy_tec9;"
alias FullBuyNoGun "buy_vesthelm; buy_hegrenade; buy_flashbang; buy_flashbang; buy_smoke; buy_tec9; buy_defuser;"
alias HalfBuySG "buy_sg; buy_vesthelm;"
alias HalfBuyM4 "buy_ak; buy_vesthelm;"
alias ArmorGoodPistol "buy_tec9; buy_vest; buy_vesthelm;"
alias ArmorBadPistol "buy_p250; buy_vest; buy_vesthelm;"
alias GrenadeSuite "buy_hegrenade; buy_flashbang; buy_flashbang; buy_smoke;"
alias BudgetGrenadeSuite "buy_flashbang; buy_smoke;"

// main buy menu
alias NumpadBuyMenu1 "bind KP_HOME buy_sg"
alias NumpadBuyMenu2 "bind KP_DEL buy_ak"
alias NumpadBuyMenu3 "bind KP_UPARROW buy_p90"
alias NumpadBuyMenu4 "bind KP_PGUP buy_tec9"
alias NumpadBuyMenu5 "bind KP_LEFTARROW buy_hegrenade"
alias NumpadBuyMenu6 "bind KP_5 buy_flashbang"
alias NumpadBuyMenu7 "bind KP_RIGHTARROW buy_smoke"
alias NumpadBuyMenu8 "bind KP_MULTIPLY buy_molotov"
alias NumpadBuyMenu9 "bind KP_SLASH buy_defuser"
alias NumpadBuyMenu10 "bind KP_PLUS buy_vesthelm"
alias NumpadBuyMenu11 "bind KP_ENTER buy_vest"
alias NumpadBuyMenu12 "bind KP_MINUS buy_defuser"

alias NumpadBuyMenu13 "bind KP_END HalfBuySG;"
alias NumpadBuyMenu14 "bind KP_DOWNARROW HalfBuyM4;"
alias NumpadBuyMenu15 "bind KP_PGDN FullBuyNoGun;"
alias NumpadBuyMenu16 "bind KP_INS GrenadeSuite"

alias NumpadBuyMenu "NumpadBuyMenu1; NumpadBuyMenu2; NumpadBuyMenu3; NumpadBuyMenu4; NumpadBuyMenu5; NumpadBuyMenu6; NumpadBuyMenu7; NumpadBuyMenu8; NumpadBuyMenu9; NumpadBuyMenu10; NumpadBuyMenu11; NumpadBuyMenu12; NumpadBuyMenu13; NumpadBuyMenu14; NumpadBuyMenu15; NumpadBuyMenu16;"

// alternate buy menu
alias AltNumpadBuyMenu1 "bind KP_HOME buy_famas"
alias AltNumpadBuyMenu2 "bind KP_DEL buy_awp"
alias AltNumpadBuyMenu3 "bind KP_UPARROW buy_ump45"
alias AltNumpadBuyMenu4 "bind KP_PGUP buy_p250"
alias AltNumpadBuyMenu5 "bind KP_LEFTARROW buy_molotov"
alias AltNumpadBuyMenu6 "bind KP_5 buy_decoy"
alias AltNumpadBuyMenu7 "bind KP_RIGHTARROW buy_smoke"
alias AltNumpadBuyMenu8 "bind KP_MULTIPLY buy_molotov"
alias AltNumpadBuyMenu9 "bind KP_SLASH buy_defuser"
alias AltNumpadBuyMenu10 "bind KP_PLUS buy_vesthelm"
alias AltNumpadBuyMenu11 "bind KP_ENTER buy_vest"
alias AltNumpadBuyMenu12 "bind KP_MINUS buy_defuser"

alias AltNumpadBuyMenu13 "bind KP_END ArmorGoodPistol;"
alias AltNumpadBuyMenu14 "bind KP_DOWNARROW ArmorBadPistol;"
alias AltNumpadBuyMenu15 "bind KP_PGDN buy_defuser;"
alias AltNumpadBuyMenu16 "bind KP_INS BudgetGrenadeSuite;"

alias AltNumpadBuyMenu "AltNumpadBuyMenu1; AltNumpadBuyMenu2; AltNumpadBuyMenu3; AltNumpadBuyMenu4; AltNumpadBuyMenu5; AltNumpadBuyMenu6; AltNumpadBuyMenu7; AltNumpadBuyMenu8; AltNumpadBuyMenu9; AltNumpadBuyMenu10; AltNumpadBuyMenu11; AltNumpadBuyMenu12; AltNumpadBuyMenu13; AltNumpadBuyMenu14; AltNumpadBuyMenu15; AltNumpadBuyMenu16;"

alias +BindAltNumpadBuyMenu "AltNumpadBuyMenu;"
alias -BindAltNumpadBuyMenu "NumpadBuyMenu;"

//----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------Binds
//----------------------------------------------------------------------------------
bind MWHEELUP ""
bind MWHEELDOWN ""
bind mouse3 "+KnifeAttack;"
bind mouse4 +MouseModifier
bind space "+JumpCrouch;"
bind alt "+BindAltNumpadBuyMenu;"
bind RCTRL +jump
bind q UseKnife;
bind f "use weapon_flashbang"
bind 3 TakeOutSmoke

//buy
NumpadBuyMenu

// misc
bind del ignoremsg
bind pgdn VoiceOn
bind pgup showviewmodel
bind f5 quit
bind f8 disconnect
bind ins showcrosshair
bind f4 displaydamage
bind TAB +ScoreNet
bind f12 "exec autoexec"
bind f11 "exec practice"
bindtoggle f10 sv_showimpacts
bindtoggle f9 sv_cheats
bind pgdn VoiceOn;
bind pgup showviewmodel

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------HUD Settings
//----------------------------------------------------------------------------------
cl_hud_background_alpha "0.5"
cl_hud_bomb_under_radar "0"
cl_hud_color "0"
cl_hud_healthammo_style "0"
cl_hud_playercount_pos "0"
cl_hud_playercount_showcount "0"
cl_hud_radar_scale "1.100000"
hud_scaling "0.850000"
hud_showtargetid "1"
hud_takesshots "0"
//Host_WriteConfiguration: Wrote cfg/hud_shareconfig.cfg
cl_radar_always_centered "1"
cl_radar_icon_scale_min "0.600000"
cl_radar_rotate "1"
cl_radar_scale "0.350000"
cl_radar_square_with_scoreboard "1"
