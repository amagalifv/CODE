<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="EliminarSucursal.aspx.cs" Inherits="TP5_AMFV.EliminarSucursal" %>

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
            width: 220px;
        }
        .auto-style3 {
            width: 400px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
        <div>
            <table class="auto-style1">
                <tr>
                    <td>
                        <asp:HyperLink ID="hlAgregarSuc" runat="server" Font-Underline="True" ForeColor="Blue" NavigateUrl="~/AgregarSucursal.aspx">Agregar sucursal</asp:HyperLink>
                    </td>
                    <td>
                        <asp:HyperLink ID="hlListadoSuc" runat="server" Font-Underline="True" ForeColor="Blue" NavigateUrl="~/ListadoDeSucursales.aspx">Listado de sucursales</asp:HyperLink>
                    </td>
                    <td>
                        <asp:HyperLink ID="hlEliminarSuc" runat="server" Font-Underline="True" ForeColor="Blue" NavigateUrl="~/EliminarSucursal.aspx">Eliminar sucursal</asp:HyperLink>
                    </td>
                </tr>
            </table>
        </div>
        </div>
        <br />
        <br />
        <asp:Label ID="Label1" runat="server" Font-Bold="True" Font-Size="XX-Large" Text="Eliminar Sucursales"></asp:Label>
        <br />
        <br />
        <table class="auto-style1">
            <tr>
                <td class="auto-style2">
                    <asp:Label ID="Label2" runat="server" Text="Ingrese ID Sucursal:"></asp:Label>
                </td>
                <td class="auto-style3">
                    <asp:TextBox ID="txtIdSucursal" runat="server" Width="389px"></asp:TextBox>
                </td>
                <td>
                    <asp:Button ID="btnAceptar" runat="server" OnClick="btnAceptar_Click" Text="Eliminar" />
                    <asp:CompareValidator ID="CompareValidator1" runat="server" ControlToValidate="txtIdSucursal" ErrorMessage="*Debe ingresar un número entero" ForeColor="Red" Operator="GreaterThanEqual" Type="Integer" ValueToCompare="0"></asp:CompareValidator>
                </td>
            </tr>
        </table>
        <br />
        <br />
        <asp:Label ID="lblResulEliminar" runat="server"></asp:Label>
    </form>
</body>
</html>
