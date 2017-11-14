Public Class Form1

    Function CalcConv(ByVal tmpCel As Double)
        Dim Far As Double
        Far = (9 / 5) * tmpCel + 32
        Return Far

    End Function

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim tmpCel As Double = -40
        Dim tmpFar As Double
        Dim fmtStr As String = "{0, -15}{1, -15}"
        lstOutput.Items.Add(String.Format(fmtStr, "Celcius", "Fahrenheit"))
        Do While (tmpCel >= -40) And (tmpCel <= 40)
            lstOutput.Items.Add(String.Format(fmtStr, tmpCel, CalcConv(tmpCel)))
            tmpCel += 5
        Loop
    End Sub
End Class
