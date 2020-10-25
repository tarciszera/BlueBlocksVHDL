#Cria biblioteca do projeto
vlib work

#compila projeto: todos os aquivo. Ordem � importante
vcom my_package.vhd tb.vhd

#Simula (work � o diretorio, testbench � o nome da entity)
vsim -t ns work.tb

#Mosta forma de onda
view wave

#Adiciona ondas espec�ficas
# -radix: binary, hex, dec
# -label: nome da forma de onda
add wave -radix dec  /outputFunc
add wave -radix binary  /outputFunc
add wave -radix dec  /outputProcMax
add wave -radix binary  /outputProcMax
add wave -radix dec  /outputProcMin
add wave -radix binary  /outputProcMin
add wave -radix dec  /outputProcEve
add wave -radix binary  /outputProcEve

#Simula at� um 50ns
run 50ns

wave zoomfull
write wave wave.ps
