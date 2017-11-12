Public Class Form1

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim assignment As String
        Dim actual, attempted, totalActual, totalAttempted, percent, letterGrade As Double
        Dim sr As IO.StreamReader = IO.File.OpenText("grades.TXT")
        Dim fmtStr As String = "{0,-22}{1,-8}{2,-10}"
        info.Items.Clear()
        info.Items.Add(String.Format(fmtStr, "Assignment", "Actual", "Attempted"))
        assignment = sr.ReadLine
        actual = CDbl(sr.ReadLine)
        attempted = CDbl(sr.ReadLine)
        totalActual = actual
        totalAttempted = attempted
        info.Items.Add(String.Format(fmtStr, assignment, actual, attempted))
        assignment = sr.ReadLine
        actual = CDbl(sr.ReadLine)
        attempted = CDbl(sr.ReadLine)
        totalActual += actual
        totalAttempted += attempted
        info.Items.Add(String.Format(fmtStr, assignment, actual, attempted))
        assignment = sr.ReadLine
        actual = CDbl(sr.ReadLine)
        attempted = CDbl(sr.ReadLine)
        totalActual += actual
        totalAttempted += attempted
        info.Items.Add(String.Format(fmtStr, assignment, actual, attempted))
        assignment = sr.ReadLine
        actual = CDbl(sr.ReadLine)
        attempted = CDbl(sr.ReadLine)
        totalActual += actual
        totalAttempted += attempted
        info.Items.Add(String.Format(fmtStr, assignment, actual, attempted))
        assignment = sr.ReadLine
        actual = CDbl(sr.ReadLine)
        attempted = CDbl(sr.ReadLine)
        totalActual += actual
        totalAttempted += attempted
        info.Items.Add(String.Format(fmtStr, assignment, actual, attempted))
        assignment = sr.ReadLine
        actual = CDbl(sr.ReadLine)
        attempted = CDbl(sr.ReadLine)
        totalActual += actual
        totalAttempted += attempted
        info.Items.Add(String.Format(fmtStr, assignment, actual, attempted))
        assignment = sr.ReadLine
        actual = CDbl(sr.ReadLine)
        attempted = CDbl(sr.ReadLine)
        totalActual += actual
        totalAttempted += attempted
        info.Items.Add(String.Format(fmtStr, assignment, actual, attempted))
        assignment = sr.ReadLine
        actual = CDbl(sr.ReadLine)
        attempted = CDbl(sr.ReadLine)
        totalActual += actual
        totalAttempted += attempted
        info.Items.Add(String.Format(fmtStr, assignment, actual, attempted))
        assignment = sr.ReadLine
        actual = CDbl(sr.ReadLine)
        attempted = CDbl(sr.ReadLine)
        sr.Close()
        totalActual += actual
        totalAttempted += attempted
        info.Items.Add(String.Format("Total Actual = " & totalActual))
        info.Items.Add(String.Format("Total Attempted = " & totalAttempted))
        percent = ((totalActual / totalAttempted) * 100)
        info.Items.Add(String.Format("Percentage = " & percent))
        letterGrade = percent
        Select Case letterGrade
            Case "90" To "100"
                grade.Text = "A"
            Case "80" To "89"
                grade.Text = "B"
            Case "70" To "79"
                grade.Text = "C"
            Case "60" To "69"
                grade.Text = "D"
            Case "0" To "59"
                grade.Text = "F"
        End Select
    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

    End Sub
End Class
