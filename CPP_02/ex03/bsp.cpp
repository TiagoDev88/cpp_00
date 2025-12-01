
#include "Point.hpp"
#include "Fixed.hpp"

/*
    A ideia é dividir o triângulo principal ABC em três triângulos menores:
        ABP, BCP e CAP (onde P é o ponto a testar).

    Para calcular a área de um triângulo definido por três pontos (X1,Y1), (X2,Y2), (X3,Y3),
    utilizamos a fórmula baseada no determinante:

        area = abs( X1*(Y2 - Y3)
                   + X2*(Y3 - Y1)
                   + X3*(Y1 - Y2) ) / 2

    O ponto P está dentro do triângulo ABC se:
        area(ABP) + area(BCP) + area(CAP) == area(ABC)

    Se qualquer uma das sub-áreas for igual a 0, significa que o ponto está na borda,
    e pela regra do exercício deve ser considerado "fora".
*/

/*
    Verifica se o ponto P está dentro do triângulo ABC.

    O método divide o triângulo principal (ABC) em três triângulos menores:
        ABP, BCP e CAP.

    A soma das áreas dos três triângulos menores deve ser igual à área total ABC
    para que P esteja dentro da figura.

    Regras do exercício:
        - Se qualquer sub-área for 0, significa que P está na borda → retornar false.
        - Se a soma das áreas for diferente da área total → P está fora.
        - Apenas se as três sub-áreas forem positivas e a soma for exata → P está dentro.
*/

// Area = | x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2) |
static Fixed area(const Point a, const Point b, const Point c)
{
    Fixed areaA = a.getX() * (b.getY() - c.getY());
    Fixed areaB = b.getX() * (c.getY() - a.getY());
    Fixed areaC = c.getX() * (a.getY() - b.getY());
    Fixed total(areaA + areaB + areaC);

    if (total < Fixed(0))
        total = total * Fixed(-1);
    return total;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = area(a, b, c);

    // VERIFICAR SE A AREA DE A B C E' 0. QUER DIZER QUE E UMA LINHA.
    // RETORNO FALSO.
    if (areaABC == Fixed(0))
        return false;

    Fixed areaABP = area(a, b, point);
    Fixed areaBCP = area(b, c, point);
    Fixed areaCAP = area(c, a, point);

    //NA FUNCAO AREA, VERIFICAR SE O RESULTADO E MENOR QUE 0
    // PORQUE PODE DAR VALOR NEGATIVOS, CASO O ABP, ESTEJA EM
    // SENTIDO HORARIO OU ANTI-HORARIO.
    // CASO SEJA MENOR QUE 0, DAR A VOLTA AO RESULTADO
    // EX: RESULT = RESULT * FIXED(-1);
    // PARA TORNAR POSITIVO O VALOR
    // PORQUE UMA AREA E SEMPRE POSITIVA.
    // POSSO TAMBEM TENTAR FAZER RESULT = -RESULT;
    // MAS TENHO QUE VERIFICAR SE TENHO UM UNARIO.

    //VERIFICAR SE AS SUB AREAS (VERTICES POR EX: A B P) SAO IGUAL A 0
    // PORQUE DIVIDO O TRIANGULO PRINCIPAL EM TRIANGULOS PEQUENOS
    // E SE DER 0 QUER DIZER QUE ESTOU EM CIMA DA LINHA COM O P
    // ABP = 0   (P está em cima da linha AB)
    if (areaABP == Fixed(0) || areaCAP == Fixed(0) || areaBCP == Fixed(0))
        return false;
    
    if ((areaABP + areaCAP + areaBCP) != areaABC)
        return false;

    //CASO ESTEJA NA BORDA TAMBEM, TEM QUE RETORNAR FALSE.
    // POSSO FAZER ESSE TESTE DENTRO DA FUNCAO AREA.
    
    //CASO CONTRARIO E VERDADE.
    return true;
}