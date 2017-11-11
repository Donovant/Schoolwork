Public Class Form1

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim teamName As String
        Dim totalWon As Double
        Dim totalLost As Double
        Dim percentage As Double
        Dim total As Double
        totalWon = CDbl(Won.Text)
        totalLost = CDbl(Lost.Text)
        Total = totalWon + totalLost
        percentage = totalWon / Total
        teamName = Team.Text
        Output.Text = teamName & " won " & FormatNumber(percentage, 5) * 100 & " percent of its games."
    End Sub
End Class
