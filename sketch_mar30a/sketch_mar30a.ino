#define DWH(pin) digitalWrite(pin, HIGH)
#define DWL(pin) digitalWrite(pin, LOW)
#define SP Serial.print
#define SPL Serial.println
#define SB Serial.begin 
#define DR digitalRead 

// Definimos un struct para cada producto
struct Producto {
  String nombre; // Nombre del producto
  int cantidad; // Cantidad disponible
  float precio; // Precio del producto
  float precio_lote; // Precio del lote completo
};

Producto snack = {"Snack", 10, 5.50, 55.0};// multiplico cantidad x precio para obtener el precio del lote 
Producto refresco = {"Refresco", 8, 2.00, 16.0};
Producto sandwich = {"Sandwich", 5, 3.50, 17.5};
Producto dulces = {"Dulces", 20, 1.10, 22.0};

int pinBotonSUBIR = 2;
int pinBotonBAJAR = 3;
int pinBotonSELECCION = 4;
int pinLED = 13;

Producto productos[] = {snack, refresco, sandwich, dulces};
int opcion = 0; // variable para almacenar la opción seleccionada



void setup() {
  SB(9600);
  pinMode(pinBotonSUBIR, INPUT_PULLUP);
  pinMode(pinBotonBAJAR, INPUT_PULLUP);
  pinMode(pinBotonSELECCION, INPUT_PULLUP);
   SPL("Bienvenido a la máquina expendedora!");
  SP(opcion + 1);
  SP(". ");
  SPL(productos[opcion].nombre);
  SP(" - $");
  SPL(productos[opcion].precio);
  SP(" - Disponible:");
  SP(productos[opcion].cantidad);
  SP(" - Lote: ");
  SPL(productos[opcion].precio_lote);
}

void loop() {
  // Esperamos a que se presione el botón de subir
  if (DR(pinBotonSUBIR) == LOW) {
    opcion++;
    if (opcion > 3) {
      opcion = 0;
    }
    delay(200);
     SP(opcion + 1);
  SP(". ");
  SPL(productos[opcion].nombre);
  SP(" - $");
  SPL(productos[opcion].precio);
  SP(" - Disponible:");
  SP(productos[opcion].cantidad);
  SP(" - Lote: ");
  SPL(productos[opcion].precio_lote);
  }

  // Esperamos a que se presione el botón de bajar
  if (DR(pinBotonBAJAR) == LOW) {
    opcion--;
    if (opcion < 0) {// si menu llega a cero se salta al ultimo numero 
      opcion = 3;
    }
  
    delay(200);
  SP(opcion + 1);
  SP(". ");
  SPL(productos[opcion].nombre);
  SP(" - $");
  SPL(productos[opcion].precio);
  SP(" - Disponible:");
  SP(productos[opcion].cantidad);
  SP(" - Lote: ");
  SPL(productos[opcion].precio_lote);

  }
}
