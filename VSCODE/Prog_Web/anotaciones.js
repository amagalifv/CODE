// FUNCIONES Y METODOS

//Mensaje desde función
function mensaje () {
    console.log('texo texto');
}
mensaje();

//Mensaje como argumento de la función
function mensaje (msj) {
    console.log(msj);
}
var msj='texo texto';
mensaje(msj);

//Retornando 1 valor (como devolución de la función)
function mensaje () {
    return 'texo texto';
}
var msj=mensaje();
console.log(msj);

//ARGUMENTOS DE FUNCIONES

function sumar(a,b,c=0) {
    return a+b+c;
}
var result=sumar(4,5,8);
console.log(result);

var result= sumar(1,5);
console.log(result);

//de igual manera
var sumar = function (a,b,c=0) {
    return a+b+c;
}
var result=sumar(4,5,8);
console.log(result);

var result= sumar(1,5);
console.log(result);