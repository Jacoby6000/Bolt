#ifndef _BOLT_BROWSER_HXX_
#define _BOLT_BROWSER_HXX_

#include "browser/common.hxx"
#include "browser/window_delegate.hxx"

namespace Browser {
	/// Represents a visible browser window on the user's screen. This struct wraps a single pointer,
	/// so it is safe to store anywhere and move around during operation.
	/// The window will exist either until the user closes it or Window::Close() is called.
	/// In both cases, CefLifeSpanHandler::OnBeforeClose callback will be called (implemented by Client).
	struct Window {
		Window(CefRefPtr<CefClient> client, Details);
		void Close();
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;
		private: CefRefPtr<WindowDelegate> window_delegate;
	};
}

#endif
