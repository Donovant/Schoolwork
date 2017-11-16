Public Class Form1

    Private Sub btnCalculate_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnCalculate.Click
        Dim num, smallest, largest As Double
        Dim sr As IO.StreamReader = IO.File.OpenText("numbers.txt")
        num = sr.ReadLine
        lstNumbers.Items.Add(num)
        num = smallest
        num = largest
        Do While sr.Peek <> -1
            num = sr.ReadLine
            lstNumbers.Items.Add(num)
            If num < smallest Then
                smallest = num
            End If
            If num > largest Then
                largest = num
            End If
        Loop
        sr.Close()
        txtSmall.Text = smallest
        txtLarge.Text = largest
    End Sub
End Class
