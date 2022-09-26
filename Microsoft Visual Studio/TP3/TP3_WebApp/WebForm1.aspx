<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="TP3_WebApp.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
        .auto-style2 {
            height: 23px;
        }
        .auto-style3 {
            height: 30px;
        }
        .auto-style4 {
            height: 45px;
        }
        .auto-style5 {
            height: 26px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <table class="auto-style1">
                <tr>
                    <td class="auto-style2">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;</td>
                    <td class="auto-style2">&nbsp;</td>
                    <td class="auto-style2">
                        <asp:Label ID="lblTitleLoc" runat="server" Font-Bold="True" Font-Size="XX-Large" Text="Localidades"></asp:Label>
                        <br />
                        <br />
                    </td>
                    <td class="auto-style2">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;</td>
                </tr>
                <tr>
                    <td class="auto-style5"></td>
                    <td class="auto-style5">
                        <asp:Label ID="lblNomLoc" runat="server" Text="Nombre de localidad:"></asp:Label>
                    </td>
                    <td class="auto-style5">
                        <asp:TextBox ID="txtGuardarLoc" runat="server"></asp:TextBox>
                        <br />
                    </td>
                    <td class="auto-style5">
                        <asp:Label ID="lblAlerta" runat="server" ForeColor="Red"></asp:Label>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>
                        <br />
                        <asp:Button ID="btnGuardarLoc" runat="server" OnClick="btnGuardarLoc_Click" Text="Guardar localidad" />
                        <br />
                    </td>
                    <td>&nbsp;</td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>
                        <br />
                        <br />
                        <asp:Label ID="lblTitleUse" runat="server" Font-Bold="True" Font-Size="XX-Large" Text="Usuarios"></asp:Label>
                        <br />
                        <br />
                    </td>
                    <td>&nbsp;</td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td>
                        <asp:Label ID="lblNomUse" runat="server" Text="Nombre usuario:"></asp:Label>
                    </td>
                    <td>
                        <asp:TextBox ID="txtNomUse" runat="server"></asp:TextBox>
                    </td>
                    <td>
                        <asp:Label ID="lblAlertaNomUse" runat="server" ForeColor="Red"></asp:Label>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td>
                        <asp:Label ID="lblContrasenia" runat="server" Text="Contraseña:"></asp:Label>
                    </td>
                    <td>
                        <asp:TextBox ID="txtContrasenia" runat="server"></asp:TextBox>
                    </td>
                    <td>
                        <asp:Label ID="lblAlertaPass" runat="server" ForeColor="Red"></asp:Label>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td>
                        <asp:Label ID="lblRepeCont" runat="server" Text="Repetir contraseña:"></asp:Label>
                    </td>
                    <td>
                        <asp:TextBox ID="txtRepeCont" runat="server"></asp:TextBox>
                    </td>
                    <td>
                        <asp:Label ID="lblAlertaPassRepe" runat="server" ForeColor="Red"></asp:Label>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td>
                        <asp:Label ID="lblCorreo" runat="server" Text="Correo electrónico:"></asp:Label>
                    </td>
                    <td>
                        <asp:TextBox ID="txtMail" runat="server"></asp:TextBox>
                    </td>
                    <td>
                        <asp:Label ID="lblAlertaMail" runat="server" ForeColor="Red"></asp:Label>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td>
                        <asp:Label ID="lblCp" runat="server" Text="CP:"></asp:Label>
                    </td>
                    <td>
                        <asp:TextBox ID="txtCP" runat="server"></asp:TextBox>
                    </td>
                    <td>
                        <asp:Label ID="lblAlertaCP" runat="server" ForeColor="Red"></asp:Label>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style4"></td>
                    <td class="auto-style4">
                        <asp:Label ID="lblLocalidades" runat="server" Text="Localidades:"></asp:Label>
                    </td>
                    <td class="auto-style4">
                        <asp:DropDownList ID="ddlLocalidades" runat="server">
                        </asp:DropDownList>
                        <br />
                    </td>
                    <td class="auto-style4"></td>
                </tr>
                <tr>
                    <td class="auto-style3"></td>
                    <td class="auto-style3"></td>
                    <td class="auto-style3">
                        <br />
                        <asp:Button ID="btnGuardarUse" runat="server" OnClick="btnGuardarUse_Click" Text="Guardar Usuario" />
                        <br />
                    </td>
                    <td class="auto-style3">
                        <asp:Label ID="lblAlertaGuardado" runat="server"></asp:Label>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td>
                        <br />
                        <asp:Button ID="btnIrInicio" runat="server" Text="Ir a Inicio .aspx" OnClick="btnIrInicio_Click" />
                        <br />
                    </td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                </tr>
            </table>
        </div>
    </form>
</body>
</html>
