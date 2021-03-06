#Cria biblioteca do projeto
vlib work

#compila projeto: todos os aquivo. Ordem é importante
vcom reg.vhd testbench.vhd

#Simula (work é o diretorio, testbench é o nome da entity)
vsim -t ns work.tb

#Mosta forma de onda
view wave

#Adiciona ondas específicas
# -radix: binary, hex, dec
# -label: nome da forma de onda
add wave -radix binary  /clk
add wave -radix binary  /clk_ena
add wave -radix binary  /sclr_n
add wave -radix binary  /datain
add wave -radix binary  /reg_out

#Simula até um 500ns
run 500ns

wave zoomfull
write wave wave.ps
