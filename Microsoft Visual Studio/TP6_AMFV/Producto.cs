using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace TP6_AMFV.Clases
{
    public class Producto
    {
        private int idProducto;
        private String nomProducto;
        private String CantxUnidad;
        private decimal precioProUnidad;


        public Producto() { }

        public Producto(int id, String nombre, String cantidad, decimal precio)
        {
            this.idProducto = id;
            this.nomProducto = nombre;
            this.CantxUnidad = cantidad;
            this.precioProUnidad = precio;
        }

        public int idP
        {
            get { return idProducto; }
            set { idProducto = value; }
        }

        public String nombreP
        {
            get { return nomProducto;}
            set { nomProducto = value; }
        }
        public String cantidadXuni
        {
            get { return CantxUnidad; }
            set { CantxUnidad = value; }
        }

        public decimal precioP
        {
            get { return precioProUnidad; }
            set { precioProUnidad = value; }
        }
    }
}