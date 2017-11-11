Public Class Form1

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim college As String
        Dim enrollment As Double
        Dim faculty As Double
        Dim ratio As String
        Dim totalStudent As Double
        Dim totalFaculty As String
        Dim antecedent As Integer
        Dim consequent As String
        Dim totalRatio As String
        Dim totalAntecedent As Integer
        Dim totalConsequent As String
        Dim sr As IO.StreamReader = IO.File.OpenText("3-3-E78.txt")
        Dim fmtStr As String = "{0, -28} {1, -4}"
        Output.Items.Clear()
        Output.Items.Add(String.Format(fmtStr, "College", "Ratio"))
        college = sr.ReadLine
        enrollment = CDbl(sr.ReadLine)
        faculty = CDbl(sr.ReadLine)
        antecedent = enrollment / faculty
        consequent = ":1 "
        ratio = antecedent & consequent
        totalStudent = enrollment
        totalFaculty = faculty
        Output.Items.Add(String.Format(fmtStr, college, ratio))
        college = sr.ReadLine
        enrollment = CDbl(sr.ReadLine)
        faculty = CDbl(sr.ReadLine)
        antecedent = enrollment / faculty
        consequent = ":1 "
        ratio = antecedent & consequent
        totalStudent = totalStudent + enrollment
        totalFaculty = totalFaculty + faculty
        Output.Items.Add(String.Format(fmtStr, college, ratio))
        college = sr.ReadLine
        enrollment = CDbl(sr.ReadLine)
        faculty = CDbl(sr.ReadLine)
        antecedent = enrollment / faculty
        consequent = ":1 "
        ratio = antecedent & consequent
        totalStudent = totalStudent + enrollment
        totalFaculty = totalFaculty + faculty
        Output.Items.Add(String.Format(fmtStr, college, ratio))
        totalStudent = totalStudent + enrollment
        totalFaculty = totalFaculty + faculty
        totalAntecedent = totalStudent / totalFaculty
        totalConsequent = ":1 "
        totalRatio = totalAntecedent & totalConsequent
        Output.Items.Add(String.Format(fmtStr, "Total", totalRatio))

        sr.Close()

    End Sub
End Class
