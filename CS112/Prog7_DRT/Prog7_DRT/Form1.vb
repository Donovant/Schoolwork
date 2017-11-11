Public Class Form1
    Private Sub ratesBtn_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ratesBtn.Click 
        Dim Price As String
        Dim halfDay As Double
        Dim fullDay As Double
        Dim sr As IO.StreamReader = IO.File.OpenText("4-Sum-E1.txt")
        Dim fmtStr As String = "{0, -22} {1, -10} {2, -10}"
        table.Items.Clear()
        table.Items.Add(String.Format(fmtStr, "Price of Equipment", "Half-Day", "Full-Day"))
        Price = sr.ReadLine
        halfDay = CDbl(sr.ReadLine)
        fullDay = CDbl(sr.ReadLine)
        table.Items.Add(String.Format(fmtStr, Price, FormatCurrency(halfDay), FormatCurrency(fullDay)))
        Price = sr.ReadLine
        halfDay = CDbl(sr.ReadLine)
        fullDay = CDbl(sr.ReadLine)
        table.Items.Add(String.Format(fmtStr, Price, FormatCurrency(halfDay), FormatCurrency(fullDay)))
        Price = sr.ReadLine
        halfDay = CDbl(sr.ReadLine)
        fullDay = CDbl(sr.ReadLine)
        table.Items.Add(String.Format(fmtStr, Price, FormatCurrency(halfDay), FormatCurrency(fullDay)))
        Price = sr.ReadLine
        halfDay = CDbl(sr.ReadLine)
        fullDay = CDbl(sr.ReadLine)
        sr.Close()
    End Sub

    Private Sub billBtn_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles billBtn.Click
        receipt.Items.Clear()
        Dim input As String
        Dim total As Double
        Dim h1 As Double
        Dim f1 As Double
        Dim h2 As Double
        Dim f2 As Double
        Dim h3 As Double
        Dim f3 As Double
        Dim deposit As Double
        h1 = 16.0
        f1 = 24.0
        h2 = 12.0
        f2 = 18.0
        h3 = 20.0
        f3 = 30.0
        deposit = 30.0
        input = 0
        receipt.Items.Add(String.Format("Receipt from Eddie's Equipment Rental"))
        If equip.Text = 1 And duration.Text = "H" Then
            input = "Rug cleaner     " & FormatCurrency(h1) & " (Half day rental)"
            total = h1 + deposit
        ElseIf equip.Text = 1 And duration.Text = "F" Then
            input = "Rug cleaner     " & FormatCurrency(f1) & " (Full day rental)"
            total = f1 + deposit
        ElseIf equip.Text = 2 And duration.Text = "H" Then
            input = "Lawn mower      " & FormatCurrency(h2) & " (Half day rental)"
            total = h2 + deposit
        ElseIf equip.Text = 2 And duration.Text = "F" Then
            input = "Lawn mower      " & FormatCurrency(f2) & " (Full day rental)"
            total = f2 + deposit
        ElseIf equip.Text = 3 And duration.Text = "H" Then
            input = "Paint sprayer   " & FormatCurrency(h3) & " (Half day rental)"
            total = h3 + deposit
        ElseIf equip.Text = 3 And duration.Text = "F" Then
            input = "Paint sprayer   " & FormatCurrency(f3) & " (Full day rental)"
            total = f3 + deposit
        End If
        receipt.Items.Add(Space(0))
        receipt.Items.Add(String.Format(input))
        receipt.Items.Add(String.Format("Deposit         $30.00"))
        receipt.Items.Add(Space(0))
        receipt.Items.Add(String.Format("Total           " & FormatCurrency(total)))
    End Sub
End Class
