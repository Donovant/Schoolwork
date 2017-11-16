Public Class Form1
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim year As Double = 2039
        Dim pop As Double = 12000000000
        Dim fmtStr As String = "{0, -10}{1, -20}"
        lstOutput.Items.Clear()
        lstOutput.Items.Add(String.Format(fmtStr, "Year", "Population"))
        Do While pop > 6000000
            year = (year - 40)
            pop = (pop / 2)
            lstOutput.Items.Add(String.Format(fmtStr, year, FormatNumber(pop, 0)))
        Loop
        txtYr.Text = year
    End Sub
    Function CalcYear(ByVal prevYear As Double)
        prevYear -= 40
        Return prevYear
    End Function
    Function CalcPop(ByVal newPop As Double)
        newPop = newPop / 2
        Return newPop
    End Function

End Class
