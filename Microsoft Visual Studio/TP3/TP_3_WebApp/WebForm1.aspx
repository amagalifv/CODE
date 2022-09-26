<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="TP_3_WebApp.WebForm1" %>

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
            height: 40px;
        }
        .auto-style3 {
            height: 26px;
        }
        .auto-style4 {
            width: 247px;
        }
        .auto-style5 {
            height: 40px;
            width: 247px;
        }
        .auto-style6 {
            height: 26px;
            width: 247px;
        }
        .auto-style10 {
            height: 49px;
        }
        .auto-style11 {
            width: 247px;
            height: 49px;
        }
        .auto-style12 {
            width: 237px;
        }
        .auto-style13 {
            height: 40px;
            width: 237px;
        }
        .auto-style14 {
            height: 26px;
            width: 237px;
        }
        .auto-style15 {
            width: 237px;
            height: 49px;
        }
        .auto-style16 {
            height: 59px;
        }
        .auto-style17 {
            width: 247px;
            height: 59px;
        }
        .auto-style18 {
            width: 237px;
            height: 59px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <table class="auto-style1">
                <tr>
                    <td>&nbsp;</td>
                    <td class="auto-style4">&nbsp;</td>
                    <td class="auto-style12">
                        <br />
                        <asp:Label ID="lblH1" runat="server" Font-Bold="True" Font-Size="XX-Large" Text="Localidades"></asp:Label>
                        <br />
                    </td>
                    <td>&nbsp;</td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td class="auto-style4">
                        <asp:Label runat="server" Text="Nombre de localidad:"></asp:Label>
                    </td>
                    <td class="auto-style12">
                        <asp:TextBox ID="txtLocalidad" runat="server" ValidationGroup="Grupo1"></asp:TextBox>
&nbsp;
                        <br />
                    </td>
                    <td>
                        <asp:RequiredFieldValidator ID="rfvIngreseLocalidad" runat="server" ControlToValidate="txtLocalidad" ForeColor="Red" ValidationGroup="Grupo1">*</asp:RequiredFieldValidator>
                        </td>
                </tr>
                <tr>
                    <td class="auto-style2"></td>
                    <td class="auto-style5"></td>
                    <td class="auto-style13">
                        <asp:Button ID="btnGuardarLoc" runat="server" OnClick="btnGuardarLoc_Click" Text="Guardar Localidad" ValidationGroup="Grupo1" />
                    </td>
                    <td class="auto-style2"></td>
                </tr>
                <tr>
                    <td class="auto-style16"></td>
                    <td class="auto-style17"></td>
                    <td class="auto-style18">
                        <br />
                        <asp:Label ID="Label9" runat="server" Font-Bold="True" Font-Size="XX-Large" Text="Usuarios"></asp:Label>
                        <br />
                    </td>
                    <td class="auto-style16"></td>
                </tr>
                <tr>
                    <td class="auto-style3"></td>
                    <td class="auto-style6">
                        <asp:Label ID="Label3" runat="server" Text="Nombre usuario:"></asp:Label>
                    </td>
                    <td class="auto-style14">
                        <br />
                        <asp:TextBox ID="txtUsuario" runat="server" ValidationGroup="Grupo2"></asp:TextBox>
&nbsp;&nbsp;
                        <br />
                    </td>
                    <td class="auto-style3">
                        <asp:RequiredFieldValidator ID="rfvNomUsu" runat="server" ControlToValidate="txtUsuario" ForeColor="Red" ValidationGroup="Grupo2">*</asp:RequiredFieldValidator>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td class="auto-style4">
                        <asp:Label ID="Label4" runat="server" Text="Contraseña:"></asp:Label>
                    </td>
                    <td class="auto-style12">
                        <br />
                        <asp:TextBox ID="txtPass" runat="server" TextMode="Password" ValidationGroup="Grupo2"></asp:TextBox>
&nbsp;
                        <br />
                    </td>
                    <td>
                        <asp:RequiredFieldValidator ID="rfvPass" runat="server" ControlToValidate="txtPass" ForeColor="Red" ValidationGroup="Grupo2">*</asp:RequiredFieldValidator>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style10"></td>
                    <td class="auto-style11">
                        <asp:Label ID="Label5" runat="server" Text="Repetir contraseña:"></asp:Label>
                    </td>
                    <td class="auto-style15">
                        <br />
                        <asp:TextBox ID="txtRepePass" runat="server" TextMode="Password" ValidationGroup="Grupo2"></asp:TextBox>
&nbsp;
                        <br />
                    </td>
                    <td class="auto-style10">
                        <asp:RequiredFieldValidator ID="rfvRepePass" runat="server" ControlToValidate="txtRepePass" ForeColor="Red" ValidationGroup="Grupo2">*</asp:RequiredFieldValidator>
                        <asp:CompareValidator ID="cpPassRepe" runat="server" ControlToCompare="txtPass" ControlToValidate="txtRepePass" ForeColor="Red" ValidationGroup="Grupo2">*</asp:CompareValidator>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td class="auto-style4">
                        <asp:Label ID="Label6" runat="server" Text="Correo electrónico:"></asp:Label>
                    </td>
                    <td class="auto-style12">
                        <br />
                        <asp:TextBox ID="txtMail" runat="server" ValidationGroup="Grupo2"></asp:TextBox>
&nbsp;
                        <br />
                    </td>
                    <td>
                        <asp:RequiredFieldValidator ID="rfvMail" runat="server" ControlToValidate="txtMail" ForeColor="Red" ValidationGroup="Grupo2">*</asp:RequiredFieldValidator>
                        <asp:RegularExpressionValidator ID="revMail" runat="server" ControlToValidate="txtMail" ForeColor="Red" ValidationExpression="\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*" ValidationGroup="Grupo2">*</asp:RegularExpressionValidator>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td class="auto-style4">
                        <asp:Label ID="Label7" runat="server" Text="CP:"></asp:Label>
                    </td>
                    <td class="auto-style12">
                        <br />
                        <asp:TextBox ID="txtCP" runat="server" ValidationGroup="Grupo2"></asp:TextBox>
&nbsp;
                        <br />
                    </td>
                    <td>
                        <asp:RequiredFieldValidator ID="rfvCp" runat="server" ControlToValidate="txtCP" ForeColor="Red" ValidationGroup="Grupo2">*</asp:RequiredFieldValidator>
                        <asp:RegularExpressionValidator ID="revCP" runat="server" ControlToValidate="txtCP" ForeColor="Red" ValidationExpression="[1-9]{4}" ValidationGroup="Grupo2">*</asp:RegularExpressionValidator>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td class="auto-style4">
                        <asp:Label ID="Label8" runat="server" Text="Localidades:"></asp:Label>
                    </td>
                    <td class="auto-style12">
                        <br />
                        <asp:DropDownList ID="ddlLocalidades" runat="server" ValidationGroup="Grupo2">
                            <asp:ListItem>--Seleccione Localidad --</asp:ListItem>
                        </asp:DropDownList>
&nbsp;
                        <br />
                    </td>
                    <td>
                        <asp:RequiredFieldValidator ID="rfvDdlLocalidades" runat="server" ControlToValidate="ddlLocalidades" ForeColor="Red" InitialValue="--Seleccione Localidad --" ValidationGroup="Grupo2">*</asp:RequiredFieldValidator>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td class="auto-style4">&nbsp;</td>
                    <td class="auto-style12">
                        <br />
                        <asp:Button ID="btnGuardarUsu" runat="server" OnClick="btnGuardarUsu_Click" Text="Guardar Usuario" ValidationGroup="Grupo2" />
&nbsp;&nbsp;&nbsp;&nbsp;
                        <br />
                    </td>
                    <td>
                        <asp:Label ID="lblGuardado" runat="server" ForeColor="#009900"></asp:Label>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td class="auto-style4">
                        <br />
                        <asp:Button ID="btnIrA" runat="server" OnClick="btnIrA_Click" Text="Ir a Inicio .aspx" ValidationGroup="Grupo3" />
                        <br />
                    </td>
                    <td class="auto-style12">&nbsp;</td>
                    <td>&nbsp;</td>
                </tr>
            </table>
            <br />
        </div>
    </form>
</body>
</html>
