<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="AgregarSucursal.aspx.cs" Inherits="CapaVista.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">

        .auto-style1 {
            width: 100%;
        }
        .auto-style3 {
            width: 325px;
        }
        .auto-style4 {
            height: 29px;
            width: 325px;
        }
        .auto-style2 {
            height: 29px;
        }
        .auto-style5 {
            width: 325px;
            height: 107px;
        }
        .auto-style6 {
            height: 107px;
        }
        </style>
</head>
<body>
    <form id="form2" runat="server">
        <div>
            <table class="auto-style1">
                <tr>
                    <td>
                        <asp:HyperLink ID="hlAgregarSuc" runat="server" Font-Underline="True" ForeColor="Blue" NavigateUrl="~/AgregarSucursal.aspx">Agregar sucursal</asp:HyperLink>
                    </td>
                    <td>
                        <asp:HyperLink ID="hlListadoSuc" runat="server" Font-Underline="True" ForeColor="Blue" NavigateUrl="~/ListadoSucursales.aspx">Listado de sucursales</asp:HyperLink>
                    </td>
                    <td>
                        <asp:HyperLink ID="hlEliminarSuc" runat="server" Font-Underline="True" ForeColor="Blue" NavigateUrl="~/EliminarSucursales.aspx">Eliminar sucursal</asp:HyperLink>
                    </td>
                </tr>
            </table>
        </div>
        <br />
        <br />
        <asp:Label ID="lblH1" runat="server" Font-Bold="True" Font-Size="XX-Large" Text="GRUPO N°2"></asp:Label>
        <br />
        <br />
        <br />
        &nbsp;&nbsp;&nbsp;
        <asp:Label ID="Label2" runat="server" Font-Bold="True" Font-Size="X-Large" Text="Agregar Sucursal"></asp:Label>
        <br />
        <br />
        <br />
        <br />
        <table class="auto-style1">
            <tr>
                <td class="auto-style3">&nbsp;&nbsp;&nbsp;
                    <asp:Label ID="Label3" runat="server" Text="Nombre sucursal:"></asp:Label>
                </td>
                <td>
                    <asp:TextBox ID="txtNomSuc" runat="server" Width="402px"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="txtNomSuc" ErrorMessage="* Ingrese Nombre de Sucursal" Font-Bold="False" ForeColor="Red"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style5">&nbsp;&nbsp;&nbsp;
                    <asp:Label ID="Label4" runat="server" Text="Descripción:"></asp:Label>
                </td>
                <td class="auto-style6">
                    <asp:TextBox ID="txtDescripcion" runat="server" Height="93px" Width="402px"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ControlToValidate="txtDescripcion" ErrorMessage="* Ingrese Descripción" Font-Bold="False" ForeColor="Red"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style3">&nbsp;&nbsp;&nbsp;
                    <asp:Label ID="Label5" runat="server" Text="Provincia:"></asp:Label>
                </td>
                <td>
                    <asp:DropDownList ID="ddlProvincia" runat="server">
                    </asp:DropDownList>
                </td>
            </tr>
            <tr>
                <td class="auto-style4">&nbsp;&nbsp;&nbsp;
                    <asp:Label ID="Label6" runat="server" Text="Dirección:"></asp:Label>
                </td>
                <td class="auto-style2">
                    <asp:TextBox ID="txtDireccion" runat="server" Width="401px"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" ControlToValidate="txtDireccion" ErrorMessage="* Ingrese Dirección" Font-Bold="False" ForeColor="Red"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style3">&nbsp;</td>
                <td>
                    <asp:Button ID="btnAceptar" runat="server" Text="Aceptar" OnClick="btnAceptar_Click" />
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    <asp:Label ID="lblResultAceptar" runat="server"></asp:Label>
                </td>
            </tr>
        </table>
    </form>
</body>
</html>
