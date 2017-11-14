Public Class Form1
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim fmtStr As String = "{0,-25}{1,15}"
        lstOutput.Items.Add(String.Format(fmtStr, "College", "Percent of Change"))
        getInput()

    End Sub
    Sub getInput()
        Dim College As String
        Dim tf0607, tf0708 As Double
        Dim sr As IO.StreamReader = IO.File.OpenText("Colleges.txt")
        College = sr.ReadLine
        tf0607 = CDbl(sr.ReadLine)
        tf0708 = CDbl(sr.ReadLine)
        showOutput(College, Change(tf0607, tf0708))
        College = sr.ReadLine
        tf0607 = CDbl(sr.ReadLine)
        tf0708 = CDbl(sr.ReadLine)
        showOutput(College, Change(tf0607, tf0708))
        College = sr.ReadLine
        tf0607 = CDbl(sr.ReadLine)
        tf0708 = CDbl(sr.ReadLine)
        showOutput(College, Change(tf0607, tf0708))
        College = sr.ReadLine
        tf0607 = CDbl(sr.ReadLine)
        tf0708 = CDbl(sr.ReadLine)
        showOutput(College, Change(tf0607, tf0708))
        sr.Close()
    End Sub
    Sub showOutput(ByVal College As String, ByVal percentage As Double)
        Dim txt1, txt2 As String
        Dim fmtStr As String = "{0,-25}{1,15:p}"

        lstOutput.Items.Add(String.Format(fmtStr, College, percentage))
    End Sub

    Function Change(ByVal tf0607 As Double, ByVal tf0708 As Double)
        Dim percentage As Double
        percentage = ((tf0708 - tf0607) / tf0607)
        Return percentage
    End Function
End Class
