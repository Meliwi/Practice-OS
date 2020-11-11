## Ejercicio práctico con Virtual Box 

- ¿Qué es el comando VBoxManage? 
    Es la herramienta que permite gestionar maquinas virtuales desde la terminal. 

- El comando alias nos permite definir un comando de una manera más fácil. Para crear uno se debe realizar de la siguiente
   manera: alias vb = "VBoxManage", entonces de esta forma no hay necesidad de llamar el comando VBoxManage completo, simplemente 
   se debe llamar a vb

- Lista de comandos usados en clase: 
    * VBoxManage list vms -> Muestra la lista de maquinas virtuales que se han creado hasta el momento 
    * VBoxManage list ostypes -> Muestra la lista de sistemas operativos que el reconoce. 
    * VBoxManage showvminfo nombre-maquina-virtual | less -> Me muestra las características de la maquina virtual que yo desee. 
    * VBoxManage modifyvm nombre-maquina-virtual --cpus 4 -> Nos permite cambiar el número de procesadores 
    * VBoxManage modifyvm nombre-maquina-virtual --memory 2048 -> Nos permite modificar el tamaño de la memoria de la máquina virtual 
    * VBoxManage unregistervm nombre-maquina-virtual --delete -> La máquina virtual ya no aparecerá, se desregistra, pero aún así se deben 
                                                                eliminar los discos duros porque aunque la máquina no está, hay consumo de espacio
    * VBoxManage clonevm nombre-maquina-virtual --name nuevo-nombre-maquina --register -> Clonar una máquina virtual, el --register para que se
                                                                                        muestre en la interfaz de virtualBox 
    * VBoxManage startvm nombre-maquina-virtual --type headless -> Arranca la máquina virtual pero sin mostrarla en pantalla 
    * tar xf ../base.ova -> Extraer los archivos que están dentro de un archivo 
    * VBoxManage export nombre-maquina-virtual -o filename.ova -> exportar una maquina virtual en archivo .ova
    * VBoxManage import </ruta/a/archivo/ova> -> Importar una máquina virtual 
    * VBoxManage controlvm nombre-maquina-virtual poweroff -> Apagar la máquina virtual 
    * VBoxManage snapshots nombre-maquina-virtual take nombre-snapshot -> Tomar un snapshot de una máquina virtual 
    * VBoxManage snapshots nombre-maquina-virtual list -> lista los snapshots de una máquina virtual 
    
    


                                                        
                                    