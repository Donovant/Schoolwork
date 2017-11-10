Public Class Form1

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim hrsCycle As Double = 200
        Dim hrsRun As Double = 475
        Dim hrsSwim As Double = 275
        Dim cycleBox As Double
        Dim runBox As Double
        Dim swimBox As Double
        Dim totalCycle As Double
        Dim totalRun As Double
        Dim totalSwim As Double
        Dim totalOutput As Double
        Dim weightLoss As Double
        cycleBox = CDbl(Cycling.Text)
        runBox = CDbl(Running.Text)
        swimBox = CDbl(Swimming.Text)
        totalCycle = hrsCycle * cycleBox
        totalRun = hrsRun * runBox
        totalSwim = hrsSwim * swimBox
        totalOutput = totalCycle + totalRun + totalSwim
        weightLoss = totalOutput / 3500
        Output.Text = FormatNumber(weightLoss, 2) & " pounds were lost"
    End Sub
End Class
