# calib_servomotor
Esse é o calibrador automático de motores servo desenvolvido para agilizar a vida do desenvolvedor de robôs a patas!

<img src="https://github.com/Penguin-Lab/calib_servomotor/blob/main/foto0.jpg" height="350">

## Modo de uso:
Para testar o sistema, o usuário deve:
- Conectar a ESP32 no computador e o motor na PCA9685
- Ligar o sistema com a bateria e pressionar as setas do Game Pad de forma a mexer o eixo do motor e descobrir de forma vaga valores mínimo e máximo de PWM que o motor aceita
- Posicionar de forma vaga o eixo do motor ao centro dessa faixa
- Fixar o motor na estrutura base
- Encaixar o disco no eixo do motor e apeça do ponteiro no disco
- Pressionar o botão quadrado e esperar até que o ponteiro pare na chave fim de curso
- Pressionar o botão círculo e esperar até que o ponteiro pare na chave fim de curso
- Pressionar a cruz para confirmar que o eixo se move para a marcação de centro (0 graus)
- Pressionar o triângulo para escrever no Monitor Serial da IDE do Arduino a faixa de valores para -90 e +90 graus
- Colocar a faixa estimada no arquivo Excel, que retorna a faixa PWM para 0 e 180 graus
- Com o disco posicionado na posição 0 graus, pode-se retirar o motor do sistema e conecta-lo na pata do robô a ser construído

## Aluno participante e desenvolvedor do calibrador automático de servo motor
- Samuel Gurgel Rocha
