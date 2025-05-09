#ifndef ATM_H_INCLUDED
#define ATM_H_INCLUDED
//Funcion que valida que la cantidad sea positiva.
int valida(float x)
{
    //Si la cantidad es positiva, es valida.
    if(x > 0)
    {
        printf("\nLa cantidad ingresada es valida.\n");
        return 1;
    }
    //Si la cantidad es 0, se muestra el siguiente mensaje.
    else if (x == 0)
    {
        printf("\nLa cantidad ingresada es 0.\n \nNo me hagas perder el tiempo.\n");
    }
    //Si la cantidad es negativa, se le pide al usuario que ingrese un numero positivo.
    else
    {
        printf("\nLa cantidad ingresada es NEGATIVA.\n \nIngrese un numero positivo, por favor.\n");
    }
    return 0;
}

//Funcion que valida que cuenta con el dinero que se desea retirar.
int Aceptable(float y, float saldo)
{
    if(y > 0 && y <= saldo )
    {
        //Si el usuario cuenta con la cantidad que desea retirar, te muestra este mensaje.
        printf("El retiro se puede realizar.\n");
        return 1;
    }
    else if(y > saldo)
    {
        //Si no se cuenta con esa cantidad, te muestra el siguiente mensaje y te solicita otra cantidad con la que cuentes.
        printf("\nNo cuentas con esta cantidad, no seas transa.\n");
    }
    else
    {
        //Si la cantidad es negativa se muestra esto.
        printf("\nNo puedes retirar cantidades negativas.\n");
    }
    return 0;
}


#endif // ATM_H_INCLUDED
