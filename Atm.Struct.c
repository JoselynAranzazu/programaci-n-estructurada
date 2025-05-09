#include<stdio.h>
#include<string.h>

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

struct Cliente{
    int Numcuentas;
    float cash;
    char nombre[40];
    int pin;
};

void main(void)
{
    int cuentas;
    int cuentaEncontrada = -1; //Esto indica que aún no se encuentra la cuenta.
    int c;
    struct Cliente num[3] = {
        {113, 1000, "Panchita Lopez Ramos", 1234},
        {278, 2000, "Damiano David", 5678},
        {345, 10000, "Alejandra Villareal Velez", 8910}
    };

    printf("Ingresa el numero de cuenta con la que deseas acceder:\n");
    scanf("%d", &cuentas);
    for(c = 0; c < 3; c++)
    {
        if(cuentas == num[c].Numcuentas)
        {
            cuentaEncontrada = c; //Con esto se guarda la posición donde se encontró.
            printf("Su cuenta fue encontrada: %s, puede continuar.\n", num[c].nombre);
            break;
        }
    }
    if(cuentaEncontrada == -1)
    {
        printf("Esta cuenta no existe\n");
        return 0;
    }



    int intentos = 0;
    int op, cont;
    float cantidad;
    int pin;

    int v, A;

    //Saluda al usuario y se le da la bienvenida.
    printf("===Bienvenido al cajero automatico *BBVA*===\n");

    //Verificacion del pin que permite solo 3 intentos.
    for(intentos = 0; intentos < 3; intentos++) //Se utiliza para la cantidad de intentos del pin.
    {
        //Solicita al usuario que ingrese el pin.
        printf("\nIngrese su pin de cuatro digitos:\n");
        scanf("%d", &pin);

        if(pin == num[c].pin)
        {
            printf("El pin %d es valido\n", pin);
            break;
        }
        else
        {
            //Si el pin es incorrecto, se muestra el numero de intentos.
            printf("\nEl pin es incorrecto, ingrese el pin nuevamente.\n");
            printf("\nNumero de intento %d de 3.\n", intentos+1);
        }
    }
    if (intentos == 3) // Esto es por si después de 3 intentos sigue siendo incorrecto el pin; se bloquea el acceso.
    {
        printf("\nAcceso denegado. Se bloqueara la cuenta. Para solucionar el problema, contacte a su banco.\n");
        return 0;
    }//Sale y termina el programa al bloquearse la cuenta.

    // Si el pin es correcto, se muestra el menú de operaciones.
    do{
        printf("\n===Menu de opciones===\n");//Menu del cajero.
        printf("\n=== Cajero automatico *BBVA*  ===\n\n");
        printf("1. Consultar saldo\n");
        printf("2. Depositar dinero\n");
        printf("3. Retirar dinero\n");
        printf("4. Salir\n");
        printf("\nSeleccione una opcion, por favor:\n");
        scanf("%d", &op);

        //Control del menu de opciones.
        switch(op)
        {
        case 1:
            printf("=== Consultar saldo ===\n");
            printf("Su saldo es: %.2f\n", num[c].cash); //Muestra el saldo actual.
            break;
        case 2:
            printf("=== Depositar dinero ===\n");
            printf("Ingrese la cantidad del deposito:\n");
            scanf("%f", &cantidad);
            v = valida(cantidad);

            //Verifica que la cantidad ingresada sea valida.
            while(v != 1)
            {
                printf("\nIngrese una cantidad valida:\n");
                scanf("%f", &cantidad);
                v = valida(cantidad);
            }
            num[c].cash = cantidad + num[c].cash; //Actualiza el saldo después del deposito.
            printf("\nSu nuevo saldo es: %.2f\n", num[c].cash);
            break;
        case 3:
            printf("=== Retirar dinero ===\n");
            printf("Ingrese la cantidad que desea retirar:\n");
            scanf("%f", &cantidad);
            v = valida(cantidad);
            A = Aceptable(cantidad, num[c].cash);

            //Verifica que la cantidad que se desea retirar sea valida y aceptable.
            while(v != 1 || A != 1)
            {
                printf("\nIngrese una cantidad aceptable:\n");
                scanf("%f", &cantidad);
                v = valida(cantidad);
                A = Aceptable(cantidad, num[c].cash);
            }

            num[c].cash = num[c].cash - cantidad;
            printf("\nSu saldo actual es: %.2f\n", num[c].cash); //Actualiza el saldo después del retiro.
            break;
        case 4:
            printf("=== Salir ===\n");
            printf("\nGracias por preferir el cajero *BBVA*. Hasta luego, que tengas un buen dia.\n");
            return 0; //Salida del programa.

        default:
            printf("=== Ingrese una opcion que este dentro de las opciones ===\n");
            break;
            //Esto es por si elige alguna de opcion que no este dentro del menu.
        }
        printf("\nDesea realizar otra operacion? 1. Si y 2. No:\n");
        scanf("%d", &cont);

    }while(cont == 1); // Con esto se evalua si el usuario quiere realizar otra operacion y se repite el ciclo si este elige si.
    printf("\nGracias por preferir el cajero *BBVA*. Hasta luego, que tengas un buen dia.\n");

    return 0;
}

