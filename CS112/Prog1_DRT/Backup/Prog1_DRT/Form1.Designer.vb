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
        Me.LeftButton = New System.Windows.Forms.Button
        Me.RightButton = New System.Windows.Forms.Button
        Me.TextBoxOne = New System.Windows.Forms.TextBox
        Me.TextBoxTwo = New System.Windows.Forms.TextBox
        Me.TextBoxThree = New System.Windows.Forms.TextBox
        Me.SuspendLayout()
        '
        'LeftButton
        '
        Me.LeftButton.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.LeftButton.Location = New System.Drawing.Point(12, 217)
        Me.LeftButton.Name = "LeftButton"
        Me.LeftButton.Size = New System.Drawing.Size(97, 33)
        Me.LeftButton.TabIndex = 0
        Me.LeftButton.Text = "Left"
        Me.LeftButton.UseVisualStyleBackColor = True
        '
        'RightButton
        '
        Me.RightButton.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.RightButton.Location = New System.Drawing.Point(175, 217)
        Me.RightButton.Name = "RightButton"
        Me.RightButton.Size = New System.Drawing.Size(97, 33)
        Me.RightButton.TabIndex = 1
        Me.RightButton.Text = "Right"
        Me.RightButton.UseVisualStyleBackColor = True
        '
        'TextBoxOne
        '
        Me.TextBoxOne.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBoxOne.Location = New System.Drawing.Point(99, 12)
        Me.TextBoxOne.Name = "TextBoxOne"
        Me.TextBoxOne.Size = New System.Drawing.Size(100, 30)
        Me.TextBoxOne.TabIndex = 2
        Me.TextBoxOne.Text = "One"
        '
        'TextBoxTwo
        '
        Me.TextBoxTwo.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBoxTwo.Location = New System.Drawing.Point(99, 93)
        Me.TextBoxTwo.Name = "TextBoxTwo"
        Me.TextBoxTwo.Size = New System.Drawing.Size(100, 30)
        Me.TextBoxTwo.TabIndex = 3
        Me.TextBoxTwo.Text = "Two"
        '
        'TextBoxThree
        '
        Me.TextBoxThree.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBoxThree.Location = New System.Drawing.Point(99, 174)
        Me.TextBoxThree.Name = "TextBoxThree"
        Me.TextBoxThree.Size = New System.Drawing.Size(100, 30)
        Me.TextBoxThree.TabIndex = 4
        Me.TextBoxThree.Text = "Three"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(284, 262)
        Me.Controls.Add(Me.TextBoxThree)
        Me.Controls.Add(Me.TextBoxTwo)
        Me.Controls.Add(Me.TextBoxOne)
        Me.Controls.Add(Me.RightButton)
        Me.Controls.Add(Me.LeftButton)
        Me.Name = "Form1"
        Me.Text = "One, Two, Three"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents LeftButton As System.Windows.Forms.Button
    Friend WithEvents RightButton As System.Windows.Forms.Button
    Friend WithEvents TextBoxOne As System.Windows.Forms.TextBox
    Friend WithEvents TextBoxTwo As System.Windows.Forms.TextBox
    Friend WithEvents TextBoxThree As System.Windows.Forms.TextBox

End Class
