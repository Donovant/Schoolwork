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
        Me.input = New System.Windows.Forms.TextBox
        Me.lblTax = New System.Windows.Forms.Label
        Me.output = New System.Windows.Forms.TextBox
        Me.lblIncome = New System.Windows.Forms.Label
        Me.calc = New System.Windows.Forms.Button
        Me.SuspendLayout()
        '
        'input
        '
        Me.input.Location = New System.Drawing.Point(132, 21)
        Me.input.Name = "input"
        Me.input.Size = New System.Drawing.Size(100, 20)
        Me.input.TabIndex = 0
        '
        'lblTax
        '
        Me.lblTax.AutoSize = True
        Me.lblTax.Location = New System.Drawing.Point(40, 28)
        Me.lblTax.Name = "lblTax"
        Me.lblTax.Size = New System.Drawing.Size(86, 13)
        Me.lblTax.TabIndex = 1
        Me.lblTax.Text = "Taxable Income:"
        '
        'output
        '
        Me.output.Location = New System.Drawing.Point(132, 110)
        Me.output.Name = "output"
        Me.output.Size = New System.Drawing.Size(100, 20)
        Me.output.TabIndex = 2
        '
        'lblIncome
        '
        Me.lblIncome.AutoSize = True
        Me.lblIncome.Location = New System.Drawing.Point(22, 117)
        Me.lblIncome.Name = "lblIncome"
        Me.lblIncome.Size = New System.Drawing.Size(104, 13)
        Me.lblIncome.TabIndex = 3
        Me.lblIncome.Text = "Federal Income Tax:"
        '
        'calc
        '
        Me.calc.Location = New System.Drawing.Point(97, 62)
        Me.calc.Name = "calc"
        Me.calc.Size = New System.Drawing.Size(80, 30)
        Me.calc.TabIndex = 4
        Me.calc.Text = "Calculate"
        Me.calc.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(255, 150)
        Me.Controls.Add(Me.calc)
        Me.Controls.Add(Me.lblIncome)
        Me.Controls.Add(Me.output)
        Me.Controls.Add(Me.lblTax)
        Me.Controls.Add(Me.input)
        Me.Name = "Form1"
        Me.Text = "2007 Income Tax Rate"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents input As System.Windows.Forms.TextBox
    Friend WithEvents lblTax As System.Windows.Forms.Label
    Friend WithEvents output As System.Windows.Forms.TextBox
    Friend WithEvents lblIncome As System.Windows.Forms.Label
    Friend WithEvents calc As System.Windows.Forms.Button

End Class
