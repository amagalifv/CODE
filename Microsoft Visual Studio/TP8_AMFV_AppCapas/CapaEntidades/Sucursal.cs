using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CapaEntidades
{
    public class Sucursal
    {
        private int idSucursal;
        private String nombre;
        private String descripcion;
        private int idProvincia;
        private String direccion;

        public Sucursal() { }

        public Sucursal(String nom, String desc, int idProv, String dire)
        { 
            nombre = nom;
            descripcion = desc;
            idProvincia = idProv;
            direccion = dire;
        }
        public int getIdSucursal()
        {
            return idSucursal;
        }
        public void setIdSucursal(int idSucursal)
        {
            this.idSucursal = idSucursal;
        }
        public String getNombre()
        {
            return nombre;
        }
        public void setNombre(String nombreS)
        {
            this.nombre = nombreS;
        }
        public String getDescripcion()
        {
            return descripcion;
        }
        public void setDescripcion(String descripcion)
        {
            this.descripcion = descripcion;
        }
        public int getIdProvincia()
        {
            return idProvincia;
        }
        public void setIdProvincia(int idProvincia)
        {
            this.idProvincia = idProvincia;
        }
        public String getDireccion()
        {
            return direccion;
        }
        public void setDireccion(String direccion)
        {
            this.direccion = direccion;
        }
    }
}
