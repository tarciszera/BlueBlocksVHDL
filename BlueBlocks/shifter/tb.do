#Cria biblioteca do projeto
vlib work

#compila projeto: todos os aquivo. Ordem � importante
vcom shifter.vhd testbench.vhd

#Simula (work � o diretorio, testbench � o nome da entity)
vsim -t ns work.tb

#Mosta forma de onda
view wave

#Adiciona ondas espec�ficas
# -radix: binary, hex, dec
# -label: nome da forma de onda
add wave -radix binary  /shft_input
add wave -radix binary  /shft_cont
add wave -radix binary  /shft_output


#Simula at� um 500ns
run 1000ns

wave zoomfull
write wave wave.ps