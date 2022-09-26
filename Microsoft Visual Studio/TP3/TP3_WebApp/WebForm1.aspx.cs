using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text.RegularExpressions;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP3_WebApp
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            
        }

        protected void btnGuardarLoc_Click(object sender, EventArgs e)
        {
            bool flag=true;

            if (txtGuardarLoc.Text.Trim().Length == 0)
            {
                lblAlerta.ForeColor = System.Drawing.Color.Red;
                lblAlerta.Text = "Ingresar localidad";
                return;
            }
            else
            {
                lblAlerta.Text = "";

                foreach(ListItem aux in ddlLocalidades.Items)
                {
                    if(aux.Text == txtGuardarLoc.Text.Trim())
                    {
                        lblAlerta.Text = "Esa localidad ya existe, ingrese otra";
                        flag = false;
                    }
                }

                if (flag)
                {
                    ddlLocalidades.Items.Add(txtGuardarLoc.Text.Trim());
                    txtGuardarLoc.Text = "";
                    lblAlerta.Text = "";
                    lblAlertaGuardado.Text = "";
                }
            }
        }

        protected void btnGuardarUse_Click(object sender, EventArgs e)
        {
            bool bandera=true;

            // valida que haya una localidad cargada en el ddl
            if (ddlLocalidades.Items.Count == 0)
            {
                bandera = false;
                lblAlerta.Text = "Ingresar localidad";
            }
            else
            {
                lblAlerta.Text = "";//limpio la label de alerta de localidad

                // NOMBRE
                if (txtNomUse.Text.Trim().Length == 0)
                {
                    bandera = false;
                    lblAlertaNomUse.Text = "Escriba un nombre de usuario";
                }
                else
                {
                    lblAlertaNomUse.Text = "";
                }


                // CONTRASEÑA
                if (txtContrasenia.Text.Trim().Length == 0)
                {
                    bandera = false;
                    lblAlertaPass.Text = "escriba una contraseña";
                }
                else
                {
                    lblAlertaPass.Text = "";
                }


                // CONTRASEÑA2
                if (txtRepeCont.Text.Trim() != txtContrasenia.Text.Trim())
                {
                    bandera = false;
                    lblAlertaPassRepe.Text = "sus contraseñas no coinciden";
                }
                else
                {
                    lblAlertaPassRepe.Text = "";
                }


                // MAIL
                //if (txtMail.Text.Contains('@') == false && (txtMail.Text.Contains(".com")== false
                //&& txtMail.Text.Contains(".ar") == false))
                if(!Regex.IsMatch(txtMail.Text, @"^([a-z]*)@([a-z]*.[a-z]*)$"))
                {
                    bandera = false;
                    lblAlertaMail.Text = "e-mail incorrecto";
                }
                else 
                {
                    lblAlertaMail.Text = "";
                }


                // CP
                if (!Regex.IsMatch(txtCP.Text, "[1-9]{4}"))
                {
                    bandera = false;
                    lblAlertaCP.Text = "código postal incorrecto";
                }
                else 
                {
                    lblAlertaCP.Text = "";
                }
            }

            

            if (bandera)
            {
                // GUARDAR TODOS LOS DATOS de usuario??
                lblAlertaGuardado.ForeColor=System.Drawing.Color.Green;
                lblAlertaGuardado.Text = "Bienvenido usuario"+ txtNomUse.Text;
                txtNomUse.Text = "";
                txtContrasenia.Text = "";
                txtRepeCont.Text = "";
                txtMail.Text = "";
                txtCP.Text = "";
            }
            else
            {
                lblAlertaGuardado.ForeColor = System.Drawing.Color.Red;
                lblAlertaGuardado.Text = "No se guardó el usuario, error";
            }

        }

        protected void btnIrInicio_Click(object sender, EventArgs e)
        {
            Response.Redirect("WebForm2.aspx");
        }
    }
}