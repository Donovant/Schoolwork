<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.Label1 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.pizzaTxt = New System.Windows.Forms.TextBox
        Me.friesTxt = New System.Windows.Forms.TextBox
        Me.drinkTxt = New System.Windows.Forms.TextBox
        Me.computeBtn = New System.Windows.Forms.Button
        Me.lstOutput = New System.Windows.Forms.ListBox
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(59, 25)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(118, 13)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Number of pizza slices?"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(93, 55)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(84, 13)
        Me.Label2.TabIndex = 1
        Me.Label2.Text = "Number of fries?"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(64, 85)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(113, 13)
        Me.Label3.TabIndex = 2
        Me.Label3.Text = "Number of soft drinks?"
        '
        'pizzaTxt
        '
        Me.pizzaTxt.Location = New System.Drawing.Point(188, 18)
        Me.pizzaTxt.Name = "pizzaTxt"
        Me.pizzaTxt.Size = New System.Drawing.Size(38, 20)
        Me.pizzaTxt.TabIndex = 3
        '
        'friesTxt
        '
        Me.friesTxt.Location = New System.Drawing.Point(188, 48)
        Me.friesTxt.Name = "friesTxt"
        Me.friesTxt.Size = New System.Drawing.Size(38, 20)
        Me.friesTxt.TabIndex = 4
        '
        'drinkTxt
        '
        Me.drinkTxt.Location = New System.Drawing.Point(188, 78)
        Me.drinkTxt.Name = "drinkTxt"
        Me.drinkTxt.Size = New System.Drawing.Size(38, 20)
        Me.drinkTxt.TabIndex = 5
        '
        'computeBtn
        '
        Me.computeBtn.Location = New System.Drawing.Point(104, 116)
        Me.computeBtn.Name = "computeBtn"
        Me.computeBtn.Size = New System.Drawing.Size(76, 21)
        Me.computeBtn.TabIndex = 6
        Me.computeBtn.Text = "Compute Bill"
        Me.computeBtn.UseVisualStyleBackColor = True
        '
        'lstOutput
        '
        Me.lstOutput.Font = New System.Drawing.Font("Courier New", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lstOutput.FormattingEnabled = True
        Me.lstOutput.ItemHeight = 15
        Me.lstOutput.Location = New System.Drawing.Point(12, 143)
        Me.lstOutput.Name = "lstOutput"
        Me.lstOutput.Size = New System.Drawing.Size(260, 124)
        Me.lstOutput.TabIndex = 7
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(284, 281)
        Me.Controls.Add(Me.lstOutput)
        Me.Controls.Add(Me.computeBtn)
        Me.Controls.Add(Me.drinkTxt)
        Me.Controls.Add(Me.friesTxt)
        Me.Controls.Add(Me.pizzaTxt)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Name = "Form1"
        Me.Text = "Restaurant Bill"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents pizzaTxt As System.Windows.Forms.TextBox
    Friend WithEvents friesTxt As System.Windows.Forms.TextBox
    Friend WithEvents drinkTxt As System.Windows.Forms.TextBox
    Friend WithEvents computeBtn As System.Windows.Forms.Button
    Friend WithEvents lstOutput As System.Windows.Forms.ListBox

End Class
