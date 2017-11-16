Public Class Form1

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim name, firstName, middleName, lastName, fullName As String
        Dim loc, loc2 As Integer
        Dim sr As IO.StreamReader = IO.File.OpenText("name.txt")
        name = sr.ReadLine
        lstInput.Items.Add(name)
        loc = name.IndexOf(" ")
        firstName = name.Substring(0, loc)
        middleName = name.Substring(loc + 1)
        loc2 = middleName.IndexOf(" ")
        lastName = middleName.Substring(loc2 + 1)
        lstOutput.Items.Add(lastName & ", " & name.Substring(0, loc + loc2 + 1))
    End Sub
End Class
