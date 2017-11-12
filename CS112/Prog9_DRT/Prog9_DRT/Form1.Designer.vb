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
        Me.humor = New System.Windows.Forms.Button
        Me.insult = New System.Windows.Forms.Button
        Me.output = New System.Windows.Forms.TextBox
        Me.input = New System.Windows.Forms.MaskedTextBox
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(151, 21)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(71, 13)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Number (1-3):"
        '
        'humor
        '
        Me.humor.Font = New System.Drawing.Font("Microsoft Sans Serif", 10.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.humor.Location = New System.Drawing.Point(83, 79)
        Me.humor.Name = "humor"
        Me.humor.Size = New System.Drawing.Size(115, 41)
        Me.humor.TabIndex = 1
        Me.humor.Text = "&Humor"
        Me.humor.UseVisualStyleBackColor = True
        '
        'insult
        '
        Me.insult.Font = New System.Drawing.Font("Microsoft Sans Serif", 10.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.insult.Location = New System.Drawing.Point(220, 79)
        Me.insult.Name = "insult"
        Me.insult.Size = New System.Drawing.Size(115, 41)
        Me.insult.TabIndex = 2
        Me.insult.Text = "&Insult"
        Me.insult.UseVisualStyleBackColor = True
        '
        'output
        '
        Me.output.Font = New System.Drawing.Font("Courier New", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.output.Location = New System.Drawing.Point(12, 126)
        Me.output.Multiline = True
        Me.output.Name = "output"
        Me.output.ReadOnly = True
        Me.output.Size = New System.Drawing.Size(394, 36)
        Me.output.TabIndex = 4
        Me.output.TabStop = False
        '
        'input
        '
        Me.input.Location = New System.Drawing.Point(240, 21)
        Me.input.Mask = "0"
        Me.input.Name = "input"
        Me.input.Size = New System.Drawing.Size(28, 20)
        Me.input.TabIndex = 5
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(418, 174)
        Me.Controls.Add(Me.input)
        Me.Controls.Add(Me.output)
        Me.Controls.Add(Me.insult)
        Me.Controls.Add(Me.humor)
        Me.Controls.Add(Me.Label1)
        Me.Name = "Form1"
        Me.Text = "4.3 Exercise 36"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents humor As System.Windows.Forms.Button
    Friend WithEvents insult As System.Windows.Forms.Button
    Friend WithEvents output As System.Windows.Forms.TextBox
    Friend WithEvents input As System.Windows.Forms.MaskedTextBox

End Class
